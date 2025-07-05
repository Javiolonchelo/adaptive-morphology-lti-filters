#include "Filter.h"

Filter::Filter(unsigned int L) {
  this->L = L;

  incomingEdges.resize(Params::N);
  outgoingEdges.resize(Params::N);
  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      if (incomingEdges[j].size() >= Params::MAX_DEPENDENCIES || Helpers::randomDouble() < (0.95)) {
        type_layer[i][j]  = 0;
        value_layer[i][j] = 0;
        continue;
      }

      type_layer[i][j] = i >= j ? Helpers::randomInt(0, 1) * 2 : Helpers::randomInt(1, 2);
      switch (type_layer[i][j]) {
        case 1:
          value_layer[i][j] = Helpers::randomDoubleNormal();
          addGain(i, j);
          break;
        default:  // 2
          value_layer[i][j] = Helpers::randomInt(1, Params::MAX_DELAY);
          addDelay(i, j);
          break;
      }
    }
  }

  fitness       = 0;
  previousError = 0;
  state.resize(L, std::vector<double>(Params::N, 0));
}

Filter::Filter(const Json::Value& json) {
  L       = json["N"].asInt();
  fitness = json["fitness"].asDouble();

  for (int i = 0; i < (int)Params::N; i++) {
    for (int j = 0; j < (int)Params::N; j++) {
      int pos           = Params::N * i + j;
      type_layer[i][j]  = json["type_layer"][pos].asInt();
      value_layer[i][j] = json["value_layer"][pos].asDouble();
    }
  }

  edges.clear();
  gains.clear();
  delays.clear();
  incomingEdges.resize(Params::N);
  outgoingEdges.resize(Params::N);

  for (int i = 0; i < (int)Params::N; i++) {
    for (int j = 0; j < (int)Params::N; j++) {
      if (type_layer[i][j] == 1) {
        gains.emplace_back(i, j);
        edges.emplace_back(i, j);
        incomingEdges[j].push_back(i);
        outgoingEdges[i].push_back(j);
      } else if (type_layer[i][j] == 2) {
        delays.emplace_back(i, j);
        edges.emplace_back(i, j);
        incomingEdges[j].push_back(i);
        outgoingEdges[i].push_back(j);
      }
    }
  }
}

Json::Value Filter::getJson() {
  Json::Value root;
  Json::Value json_typeLayer;
  Json::Value json_valueLayer;

  for (int i = 0; i < (int)Params::N; i++) {
    for (int j = 0; j < (int)Params::N; j++) {
      int pos              = Params::N * i + j;
      json_typeLayer[pos]  = type_layer[i][j];
      json_valueLayer[pos] = value_layer[i][j];
    }
  }

  root["N"]           = Params::N;
  root["fitness"]     = fitness;
  root["type_layer"]  = json_typeLayer;
  root["value_layer"] = json_valueLayer;

  Json::Value json_output;
  for (unsigned int i = 0; i < L; i++) {
    json_output[i] = state[i][Params::N - 1];
  }
  root["output"] = json_output;

  return root;
}

void Filter::changeGainToDelay(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  gains.erase(std::remove(gains.begin(), gains.end(), id), gains.end());
  delays.push_back(id);
}

void Filter::changeDelayToGain(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  delays.erase(std::remove(delays.begin(), delays.end(), id), delays.end());
  gains.push_back(id);
}

void Filter::removeGain(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  gains.erase(std::remove(gains.begin(), gains.end(), id), gains.end());
  edges.erase(std::remove(edges.begin(), edges.end(), id), edges.end());
  incomingEdges[j].erase(std::remove(incomingEdges[j].begin(), incomingEdges[j].end(), i), incomingEdges[j].end());
  outgoingEdges[i].erase(std::remove(outgoingEdges[i].begin(), outgoingEdges[i].end(), j), outgoingEdges[i].end());
}

void Filter::removeDelay(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  delays.erase(std::remove(delays.begin(), delays.end(), id), delays.end());
  edges.erase(std::remove(edges.begin(), edges.end(), id), edges.end());
  incomingEdges[j].erase(std::remove(incomingEdges[j].begin(), incomingEdges[j].end(), i), incomingEdges[j].end());
  outgoingEdges[i].erase(std::remove(outgoingEdges[i].begin(), outgoingEdges[i].end(), j), outgoingEdges[i].end());
}

void Filter::removeUnkown(const unsigned int i, const unsigned int j) {
  switch (type_layer[i][j]) {
    case 1:
      removeGain(i, j);
      break;
    case 2:
      removeDelay(i, j);
      break;
    default:  // 0
      break;
  }
}

void Filter::removeUnkown(const std::pair<unsigned int, unsigned int> id) {
  switch (type_layer[id.first][id.second]) {
    case 1:
      removeGain(id.first, id.second);
      break;
    case 2:
      removeDelay(id.first, id.second);
      break;
    default:  // 0
      break;
  }
}

void Filter::addGain(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  if (std::find(gains.begin(), gains.end(), id) != gains.end()) { return; }
  gains.push_back(id);
  edges.push_back(id);
  incomingEdges[j].push_back(i);
  outgoingEdges[i].push_back(j);
}

void Filter::addDelay(const unsigned int i, const unsigned int j) {
  std::pair<unsigned int, unsigned int> id = std::make_pair(i, j);
  if (std::find(delays.begin(), delays.end(), id) != delays.end()) { return; }
  delays.push_back(id);
  edges.push_back(id);
  incomingEdges[j].push_back(i);
  outgoingEdges[i].push_back(j);
}

void Filter::addUnknown(const unsigned int i, const unsigned int j) {
  switch (type_layer[i][j]) {
    case 1:
      addGain(i, j);
      break;
    case 2:
      addDelay(i, j);
      break;
    default:  // 0
      break;
  }
}

void Filter::addUnknown(const std::pair<unsigned int, unsigned int> id) {
  switch (type_layer[id.first][id.second]) {
    case 1:
      addGain(id.first, id.second);
      break;
    case 2:
      addDelay(id.first, id.second);
      break;
    default:  // 0
      break;
  }
}

std::string Filter::toString() {
  std::ostringstream oss;
  unsigned int       precission = 2;

  oss << "Type Layer:" << std::endl;
  for (int i = 0; i < (int)Params::N; i++) {
    for (int j = 0; j < (int)Params::N; j++) {
#ifdef ENABLE_COLOR_OUTPUT
      if (j <= i && type_layer[i][j] == 1) {
        oss << "\x1b[1;31m";
      } else if (type_layer[i][j] == 1) {
        oss << "\x1b[1;32m";
      } else if (type_layer[i][j] == 2) {
        oss << "\x1b[1;34m";
      } else {
        oss << "\x1b[0m";
      }
#endif
      oss << std::setw(4 + precission) << type_layer[i][j] << " ";
    }
#ifdef ENABLE_COLOR_OUTPUT
    oss << "\x1b[0m";
#endif
    oss << std::endl;
  }

  oss << "\nValue Layer:" << std::endl;
  for (int i = 0; i < (int)Params::N; i++) {
    for (int j = 0; j < (int)Params::N; j++) {
#ifdef ENABLE_COLOR_OUTPUT
      float intpart;
      if (j <= i && type_layer[i][j] == 1) {
        oss << "\x1b[1;31m";
      } else if (type_layer[i][j] == 1) {
        oss << "\x1b[1;32m";
      } else if (type_layer[i][j] == 2 && std::modf(value_layer[i][j], &intpart) != 0.0) {
        oss << "\x1b[1;31m";
      } else if (type_layer[i][j] == 2) {
        oss << "\x1b[1;34m";
      } else {
        oss << "\x1b[0m";
      }
#endif
      oss << std::setw(4 + precission) << std::fixed << std::setprecision(precission) << value_layer[i][j] << " ";
    }
#ifdef ENABLE_COLOR_OUTPUT
    oss << "\x1b[0m";
#endif
    oss << std::endl;
  }

  return oss.str();
}

double Filter::getFitness() { return fitness; }

void Filter::computeFitness(std::vector<double>& input, std::vector<double>& target) {
  for (unsigned int i = 0; i < L; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      state[i][j] = 0;
    }
  }

  for (unsigned int n = 0; n < L; n++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      state[n][0] += input[n];
      for (auto source : incomingEdges[j]) {
        switch (type_layer[source][j]) {
          case 1: {
            state[n][j] += value_layer[source][j] * state[n][source];
            break;
          }
          case 2: {
            int delay = value_layer[source][j];
            if (static_cast<int>(n) >= delay) { state[n][j] += state[n - delay][source]; }
            break;
          }
          default:
            break;
        }
      }
    }
  }

  double MSE = 0;
  for (unsigned int i = 0; i < L; i++) {
    MSE += pow(state[i][Params::N - 1] - target[i], 2) / L;
  }
  MSE = sqrt(MSE);

  int memoryNeeded = 0;
  for (auto id : delays) {
    memoryNeeded += value_layer[id.first][id.second];
  }

  int numAdditions = 0;
  for (auto e : incomingEdges) {
    numAdditions += e.size();
  }
  numAdditions = std::max(numAdditions - static_cast<int>(Params::N), 0);

  // FITNESS
  fitness = 1 / ((Params::PENALTY_MSE * MSE + 1) * (Params::PENALTY_NUM_GAINS * gains.size() + 1) *
                 (Params::PENALTY_MEMORY * memoryNeeded + 1) * (Params::PENALTY_NUM_ADDITIONS * numAdditions + 1));

  if (std::isnan(fitness) || std::isinf(fitness) || fitness < 0.0f || fitness > 1.0f) { fitness = 0; }
}

void Filter::mutateEdges() {
  std::set availableTypes = {0, 1, 2};

  const unsigned int i = Helpers::randomInt() % Params::N;
  const unsigned int j = Helpers::randomInt() % Params::N;

  if (i >= j) { availableTypes.erase(1); }

  if (incomingEdges[j].size() >= Params::MAX_DEPENDENCIES) {
    type_layer[i][j]  = 0;
    value_layer[i][j] = 0;
    removeUnkown(i, j);
    return;
  } else if (incomingEdges[j].size() == 0) {
    availableTypes.erase(0);
  }

  if (availableTypes.size() == 0) { return; }

  removeUnkown(i, j);
  type_layer[i][j] = *std::next(availableTypes.begin(), Helpers::randomInt() % availableTypes.size());
  switch (type_layer[i][j]) {
    case 1:
      value_layer[i][j] = Helpers::randomDoubleNormal();
      break;
    case 2:
      value_layer[i][j] = Helpers::randomInt(1, Params::MAX_DELAY);
      break;
    default:  // 0
      value_layer[i][j] = 0;
      break;
  }
  addUnknown(i, j);
}

void Filter::mutateGains() {
  if (gains.size() == 0) { return; }
  auto id = gains[Helpers::randomInt(0, gains.size() - 1)];
  value_layer[id.first][id.second] *= Helpers::randomDoubleNormal(0, 1);
}

void Filter::mutateDelays() {
  if (delays.size() == 0) { return; }
  auto id                          = delays[Helpers::randomInt(0, delays.size() - 1)];
  value_layer[id.first][id.second] = Helpers::randomInt(1, Params::MAX_DELAY);
}

std::string Filter::exportCode() {
  std::ostringstream oss;

  oss << "#pragma once\n";
  oss << "#ifdef __cplusplus\n";
  oss << "extern \"C\" {\n";
  oss << "#endif\n\n";

  // 1. Estructura del filtro
  oss << "/**\n";
  oss << " * @brief Estructura para el filtro generado.\n";
  oss << " */\n";
  oss << "typedef struct filter {\n";

  for (unsigned int node = 0; node < Params::N; node++) {
    if (outgoingEdges[node].size() == 0 && incomingEdges[node].size() == 0) { continue; }
    oss << "    double x" << node << ";  /// < Estado de la señal en el nodo " << node << "\n";
  }

  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      switch (type_layer[i][j]) {
        case 1:  // Ganancia
          oss << "    double g_" << i << "_" << j << ";  /// < Ganancia de x" << i << " a x" << j << "\n";
          break;
        case 2:  // Retardo
          oss << "    double d_" << i << "_" << j << "[" << static_cast<unsigned int>(value_layer[i][j])
              << "];  /// < Buffer de retardo de x" << i << " a x" << j
              << " (tamaño: " << static_cast<unsigned int>(value_layer[i][j]) << ")"
              << "\n    int pos_d_" << i << "_" << j << ";  /// < Posición actual del retardo de x" << i << " a x" << j
              << "\n";
          break;
        default:  // Ninguno
          break;
      }
    }
  }

  oss << "} filter_t;\n\n";

  // 2. Prototipos de funciones
  oss << "/**\n";
  oss << " * @brief Esta función debe ser llamada antes de comenzar a procesar audio.\n";
  oss << " *\n";
  oss << " * @param f Puntero a una estructura del filtro generado.\n";
  oss << " */\n";
  oss << "inline void filter_init(filter_t* f)\n";

  // 3. Implementación de init
  oss << "{\n";
  for (unsigned int n = 0; n < Params::N; n++) {
    if (outgoingEdges[n].size() == 0 && incomingEdges[n].size() == 0) { continue; }
    oss << "    f->x" << n << " = 0.0f;\n";
  }
  oss << "\n    // Inicialización de retardos\n";

  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      switch (type_layer[i][j]) {
        case 1: {  // Ganancia
          oss << "    f->g_" << i << "_" << j << " = " << std::scientific << std::setprecision(15) << value_layer[i][j]
              << ";\n";
          break;
        }
        case 2: {  // Retardo
          unsigned int delay = static_cast<unsigned int>(value_layer[i][j]);
          oss << "    for (int k = 0; k < " << delay << "; k++) f->d_" << i << "_" << j << "[k] = 0.0f;\n";
          oss << "    f->pos_d_" << i << "_" << j << " = 0;\n";
          break;
        }
        default:  // Ninguno
          break;
      }
    }
  }
  oss << "}\n\n";
  oss << "/**\n";
  oss << " * @brief Esta función resetea el estado del filtro, incluyendo sus buffers de retardo y sus variables de "
         "estado.\n";
  oss << " *\n";
  oss << " * @param f Puntero a una estructura del filtro generado.\n";
  oss << " */\n";
  oss << "inline void filter_reset(filter_t* f)\n";

  // 4. Implementación de reset
  oss << "{\n";
  for (unsigned int n = 0; n < Params::N; n++) {
    if (outgoingEdges[n].size() == 0 && incomingEdges[n].size() == 0) { continue; }
    oss << "    f->x" << n << " = 0.0f;\n";
  }
  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      if (type_layer[i][j] == 2) {
        unsigned int delay = static_cast<unsigned int>(value_layer[i][j]);
        oss << "    for (int k = 0; k < " << delay << "; k++) f->d_" << i << "_" << j << "[k] = 0.0f;\n";
        oss << "    f->pos_d_" << i << "_" << j << " = 0;\n";
      }
    }
  }
  oss << "}\n\n";
  oss << "/**\n";
  oss << " * @brief Procesa una señal de audio mediante el filtro generado.\n";
  oss << " *\n";
  oss << " * @param f Puntero a una estructura del filtro generado.\n";
  oss << " * @param input Puntero a la señal de entrada. Debe tener al menos `num_samples` muestras.\n";
  oss << " * @param output Puntero a la señal de salida. Debe tener al menos `num_samples` muestras.\n";
  oss << " * @param num_samples Número de muestras a procesar.\n";
  oss << " */\n";
  oss << "inline void filter_process(filter_t* f, const float* input, float* output, int num_samples)\n";

  // 5. Implementación de process
  oss << "{\n";
  oss << "    for (int n = 0; n < num_samples; n++) {";
  for (unsigned int j = 0; j < Params::N; j++) {
    if (outgoingEdges[j].size() == 0 && incomingEdges[j].size() == 0) { continue; }
    oss << "\n        // x" << j << "\n";
    if (j == 0) {
      oss << "        f->x0 = input[n]";
      for (auto src : incomingEdges[0]) {
        if (type_layer[src][0] == 2) { oss << " + f->d_" << src << "_0[f->pos_d_" << src << "_0]"; }
      }
      oss << ";\n";
    } else {
      oss << "        f->x" << j << " = 0.0f";
      for (auto src : incomingEdges[j]) {
        if (type_layer[src][j] == 2) { oss << " + f->d_" << src << "_" << j << "[f->pos_d_" << src << "_" << j << "]"; }
      }
      oss << ";\n";
      for (auto src : incomingEdges[j]) {
        if (type_layer[src][j] == 1) {
          oss << "        f->x" << j << " += f->g_" << src << "_" << j << " * f->x" << src << ";\n";
        }
      }
    }
  }
  oss << "\n        // Actualización de retardos\n";
  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      if (type_layer[i][j] == 2) {
        unsigned int delay = static_cast<unsigned int>(value_layer[i][j]);
        oss << "        f->d_" << i << "_" << j << "[f->pos_d_" << i << "_" << j << "] = f->x" << i << ";\n";
        oss << "        f->pos_d_" << i << "_" << j << " = (f->pos_d_" << i << "_" << j << " + 1) % " << delay << ";\n";
      }
    }
  }
  oss << "        output[n] = f->x" << (Params::N - 1) << ";\n";
  oss << "    }\n";
  oss << "}\n\n";
  oss << "#ifdef __cplusplus\n";
  oss << "    } // __cplusplus\n";
  oss << "#endif\n";

  return oss.str();
}

void Filter::mutateReciprocal() {
  unsigned int i, j, ttl = 20;
  do {
    if (ttl-- == 0) { return; }
    i = Helpers::randomInt(0, Params::N - 1);
    j = Helpers::randomInt(0, Params::N - 1);
  } while (i == j || type_layer[i][j] == 0 || incomingEdges[j].size() >= Params::MAX_DEPENDENCIES);

  if (type_layer[i][j] == 1) {
    removeUnkown(j, i);
    type_layer[j][i]  = 2;
    value_layer[j][i] = Helpers::randomInt(1, Params::MAX_DELAY);
    addDelay(j, i);
  } else {
    if (j >= i) {
      changeDelayToGain(i, j);
      type_layer[i][j]  = 1;
      value_layer[i][j] = Helpers::randomDoubleNormal();
      removeUnkown(j, i);
      type_layer[j][i]  = 2;
      value_layer[j][i] = Helpers::randomInt(1, Params::MAX_DELAY);
      addDelay(j, i);
    } else {
      removeUnkown(j, i);
      type_layer[j][i]  = 1;
      value_layer[j][i] = Helpers::randomDoubleNormal();
      addGain(j, i);
    }
  }
}

void Filter::mutateMerge(const unsigned int type) {
  std::set<unsigned int> sinkNodes;
  std::set<unsigned int> sourceNodes;
  for (auto edge : edges) {
    if (type_layer[edge.first][edge.second] != type) continue;
    sinkNodes.insert(edge.second);
    sourceNodes.insert(edge.first);
  }
  std::set<unsigned int> i_set, j_set, k_set;
  std::set_intersection(
      sourceNodes.begin(), sourceNodes.end(), sinkNodes.begin(), sinkNodes.end(), std::inserter(j_set, j_set.begin()));

  if (sinkNodes.size() == 0 || sourceNodes.size() == 0 || j_set.size() == 0) { return; }

  std::set_union(
      sourceNodes.begin(), sourceNodes.end(), j_set.begin(), j_set.end(), std::inserter(i_set, i_set.begin()));
  std::set_union(sinkNodes.begin(), sinkNodes.end(), j_set.begin(), j_set.end(), std::inserter(k_set, k_set.begin()));

  if (i_set.size() == 0 || j_set.size() == 0 || k_set.size() == 0 || i_set.size() + j_set.size() + k_set.size() < 3) {
    return;
  }

  unsigned int i, j, k;
  unsigned int ttl = 20;
  do {
    if (ttl-- < 1) return;
    i = *std::next(i_set.begin(), Helpers::randomInt(0, i_set.size() - 1));
    j = *std::next(j_set.begin(), Helpers::randomInt(0, j_set.size() - 1));
    k = *std::next(k_set.begin(), Helpers::randomInt(0, k_set.size() - 1));
  } while (i == j || j == k || i == k || (type_layer[i][j] != type || type_layer[j][k] != type));

  removeUnkown(i, j);
  removeUnkown(i, k);
  removeUnkown(j, k);

  type_layer[i][k] = type;
  switch (type) {
    case 1:
      value_layer[i][k] = value_layer[i][j] * value_layer[j][k];
      addGain(i, k);
      break;

    default:  // 2
      value_layer[i][k] = value_layer[i][j] + value_layer[j][k];
      addDelay(i, k);
      break;
  }

  type_layer[i][j]  = 0;
  value_layer[i][j] = 0;
  type_layer[j][k]  = 0;
  value_layer[j][k] = 0;
}

void Filter::mutateConsecutiveEdges() {
  if (edges.size() < 2) return;
  unsigned int e1, e2, typeOfEdge1, typeOfEdge2;
  int          ttl = 20;
  do {
    if (ttl-- < 1) return;

    e1 = Helpers::randomInt(0, edges.size() - 1);
    e2 = Helpers::randomInt(0, edges.size() - 1);
    if (e1 == e2 || edges[e1].second != edges[e2].first || edges[e1].first == edges[e2].second) continue;

    typeOfEdge1 = type_layer[edges[e1].first][edges[e1].second];
    typeOfEdge2 = type_layer[edges[e2].first][edges[e2].second];

    if (typeOfEdge1 == 1 && edges[e2].first >= edges[e2].second) continue;
    if (typeOfEdge2 == 1 && edges[e1].first >= edges[e1].second) continue;

    break;

  } while (true);

  auto edge1 = edges[e1];
  auto edge2 = edges[e2];

  removeUnkown(edge1);
  removeUnkown(edge2);
  edges.erase(std::remove(edges.begin(), edges.end(), edge1), edges.end());
  edges.erase(std::remove(edges.begin(), edges.end(), edge2), edges.end());

  std::swap(type_layer[edge1.first][edge1.second], type_layer[edge2.first][edge2.second]);
  std::swap(value_layer[edge1.first][edge1.second], value_layer[edge2.first][edge2.second]);

  addUnknown(edge1);
  addUnknown(edge2);
}

void Filter::mutateMergeUsingLonelyNodeAsSink() {
  std::vector<unsigned int> lonelyNodes;
  for (unsigned int n = 0; n < Params::N; ++n) {
    if (incomingEdges[n].empty() && outgoingEdges[n].empty()) { lonelyNodes.push_back(n); }
  }
  if (lonelyNodes.empty()) return;

  std::vector<unsigned int>                nodesWithDelays;
  std::vector<std::multiset<unsigned int>> delayValues(Params::N);
  for (unsigned int n = 0; n < Params::N; ++n) {
    if (incomingEdges[n].size() >= 2) {
      for (const auto& edge : edges) {
        if (type_layer[edge.first][edge.second] == 2) { delayValues[n].insert(value_layer[edge.first][edge.second]); }
      }
      for (const auto& value : delayValues[n]) {
        if (delayValues[n].count(value) >= 2) {
          nodesWithDelays.push_back(n);
          break;  // Solo necesitamos un valor de retardo repetido
        }
      }
    }
  }
  if (nodesWithDelays.empty()) return;

  unsigned int nodeWithDelays = nodesWithDelays[Helpers::randomInt(0, nodesWithDelays.size() - 1)];
  unsigned int lonelyNode;
  unsigned int maxIndex = [&]() {
    unsigned int maxIndex = 0;
    for (const auto& edge : edges) {
      if (edge.second == nodeWithDelays) { maxIndex = std::max(maxIndex, edge.first); }
    }
    return maxIndex;
  }();

  unsigned int ttl = 20;
  do {
    if (ttl-- < 1) return;
    lonelyNode = lonelyNodes[Helpers::randomInt(0, lonelyNodes.size() - 1)];
  } while (lonelyNode < maxIndex);

  std::set<unsigned int> delayValuesForNode;
  for (const auto& value : delayValues[nodeWithDelays]) {
    if (delayValues[nodeWithDelays].count(value) >= 2) { delayValuesForNode.insert(value); }
  }
  if (delayValuesForNode.empty()) return;
  const auto delayValue = *std::next(delayValuesForNode.begin(), Helpers::randomInt(0, delayValuesForNode.size() - 1));

  std::vector<std::pair<unsigned int, unsigned int>> aux_edges = edges;

  for (const auto& e : aux_edges) {
    if (e.second == nodeWithDelays && type_layer[e.first][e.second] == 2 &&
        value_layer[e.first][e.second] == delayValue) {
      type_layer[e.first][e.second]  = 0;
      value_layer[e.first][e.second] = 0;

      type_layer[e.first][lonelyNode]  = 1;
      value_layer[e.first][lonelyNode] = 1.0;
      removeDelay(e.first, e.second);
      addGain(e.first, lonelyNode);
    }
  }

  addDelay(lonelyNode, nodeWithDelays);
  type_layer[lonelyNode][nodeWithDelays]  = 2;
  value_layer[lonelyNode][nodeWithDelays] = delayValue;
}

void Filter::mutateMergeUsingLonelyNodeAsSource() {
  std::vector<unsigned int> lonelyNodes;
  for (unsigned int n = 0; n < Params::N; ++n) {
    if (incomingEdges[n].empty() && outgoingEdges[n].empty()) { lonelyNodes.push_back(n); }
  }
  if (lonelyNodes.empty()) return;

  std::vector<unsigned int>                nodesWithDelays;
  std::vector<std::multiset<unsigned int>> delayValues(Params::N);
  for (unsigned int n = 0; n < Params::N; ++n) {
    if (outgoingEdges[n].size() >= 2) {
      for (const auto& edge : edges) {
        if (type_layer[edge.first][edge.second] == 2) { delayValues[n].insert(value_layer[edge.first][edge.second]); }
      }
      for (const auto& value : delayValues[n]) {
        if (delayValues[n].count(value) >= 2) {
          nodesWithDelays.push_back(n);
          break;  // Solo necesitamos un valor de retardo repetido
        }
      }
    }
  }
  if (nodesWithDelays.empty()) return;

  unsigned int nodeWithDelays = nodesWithDelays[Helpers::randomInt(0, nodesWithDelays.size() - 1)];
  unsigned int lonelyNode;
  unsigned int minIndex = [&]() {
    unsigned int minIndex = 0;
    for (const auto& edge : edges) {
      if (edge.first == nodeWithDelays) { minIndex = std::min(minIndex, edge.first); }
    }
    return minIndex;
  }();

  unsigned int ttl = 20;
  do {
    if (ttl-- < 1) return;
    lonelyNode = lonelyNodes[Helpers::randomInt(0, lonelyNodes.size() - 1)];
  } while (lonelyNode > minIndex);

  std::set<unsigned int> delayValuesForNode;
  for (const auto& value : delayValues[nodeWithDelays]) {
    if (delayValues[nodeWithDelays].count(value) >= 2) { delayValuesForNode.insert(value); }
  }
  if (delayValuesForNode.empty()) return;
  const auto delayValue = *std::next(delayValuesForNode.begin(), Helpers::randomInt(0, delayValuesForNode.size() - 1));

  std::vector<std::pair<unsigned int, unsigned int>> aux_edges = edges;

  for (const auto& e : aux_edges) {
    if (e.first == nodeWithDelays && type_layer[e.first][e.second] == 2 &&
        value_layer[e.first][e.second] == delayValue) {
      type_layer[e.first][e.second]  = 0;
      value_layer[e.first][e.second] = 0;

      type_layer[lonelyNode][e.second]  = 1;
      value_layer[lonelyNode][e.second] = 1.0;
      removeDelay(e.first, e.second);
      addGain(lonelyNode, e.second);
    }
  }

  addDelay(nodeWithDelays, lonelyNode);
  type_layer[nodeWithDelays][lonelyNode]  = 2;
  value_layer[nodeWithDelays][lonelyNode] = delayValue;
}

void Filter::crossover(const Filter& parent_1, const Filter& parent_2) {
  unsigned int column = Helpers::randomInt(1, Params::N - 2);
  this->gains.clear();
  this->delays.clear();
  this->edges.clear();
  this->incomingEdges.clear();
  this->outgoingEdges.clear();
  this->incomingEdges.resize(Params::N);
  this->outgoingEdges.resize(Params::N);
  for (unsigned int i = 0; i < Params::N; i++) {
    for (unsigned int j = 0; j < Params::N; j++) {
      if (j < column) {
        this->type_layer[i][j]  = parent_1.type_layer[i][j];
        this->value_layer[i][j] = parent_1.value_layer[i][j];
      } else {
        this->type_layer[i][j]  = parent_2.type_layer[i][j];
        this->value_layer[i][j] = parent_2.value_layer[i][j];
      }
      this->addUnknown(i, j);
    }
  }
}
