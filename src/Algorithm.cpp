#include "Algorithm.h"

int Algorithm(std::vector<double>& inputSignal,
              std::vector<double>& target,
              const unsigned int   L,
              std::string          outputFile) {
  std::vector<Filter> population(Params::POPULATION_SIZE, Filter(L));
  std::vector<Filter> offspring(Params::POPULATION_SIZE, Filter(L));

  unsigned int g                         = 0;
  double       max_fitness_ever          = 0;
  unsigned int countOfStalledGenerations = 0;

  std::cout << CLEAR_SCREEN_FR;

  do {  // Main loop
    g++;

#pragma omp parallel for
    for (auto& f : population) {
      f.computeFitness(inputSignal, target);
    }

    // SELECCIÓN
    std::ranges::sort(population, [](Filter& a, Filter& b) { return a.getFitness() > b.getFitness(); });
    unsigned int best = 0;
    for (int i = 0; i < static_cast<int>(Params::POPULATION_SIZE); i++) {
      if (population[i].getFitness() >= population[best].getFitness()) { best = i; }
    }

#pragma omp parallel for  // CRUCE
    for (auto& f : offspring) {
      double total_fitness = 0.0;
      for (unsigned int i = 0; i < Params::SURVIVORS; ++i) {
        total_fitness += population[i].getFitness();
      }

      double       pick       = Helpers::randomDouble() * total_fitness;
      double       cumulative = 0.0;
      unsigned int parent_1   = 0;
      for (unsigned int i = 0; i < Params::SURVIVORS; ++i) {
        cumulative += population[i].getFitness();
        if (cumulative >= pick) {
          parent_1 = i;
          break;
        }
      }
      if (Params::CROSSOVER_RATE > Helpers::randomDouble()) {
        unsigned int parent_2    = 0;
        double       pick2       = Helpers::randomDouble() * total_fitness;
        double       cumulative2 = 0.0;
        for (unsigned int i = 0; i < Params::SURVIVORS; ++i) {
          cumulative2 += population[i].getFitness();
          if (cumulative2 >= pick2) {
            parent_2 = i;
            break;
          }
        }
        // Aseguramos que los padres son diferentes
        if (parent_1 == parent_2) { parent_2 = (parent_2 + 1) % Params::SURVIVORS; }
        f.crossover(population[parent_1], population[parent_2]);
      } else {
        f = population[parent_1];
      }
    }

    countOfStalledGenerations =
        (offspring[best].getFitness() <= max_fitness_ever + 1e-3) ? countOfStalledGenerations + 1 : 0;
    if (offspring[best].getFitness() > max_fitness_ever) { max_fitness_ever = offspring[best].getFitness(); }

    // GUARDAR EL MEJOR INDIVIDUO EN JSON
    if (Params::SAVE_RESULTS) {
      const std::string jsonFilename = outputFile + "_Gen-" + std::to_string(g) + ".json";
      std::ofstream     file(jsonFilename, std::ios::trunc | std::ios::out);
      file << offspring[best].getJson() << std::endl;
      file.close();

      const std::string codeFilename = outputFile + "_Gen-" + std::to_string(g) + ".h";
      std::ofstream     codeFile(codeFilename, std::ios::trunc | std::ios::out);
      codeFile << offspring[best].exportCode() << std::endl;
      codeFile.close();
    }

    // MUESTRA RESULTADOS DE LA GENERACIÓN ACTUAL
    std::cout << CLEAR_SCREEN_FR;
    std::cout << "Max fitness: " << max_fitness_ever << '\n';
    std::cout << "Generation " << g << "'s fitness: " << offspring[best].getFitness() << '\n' << '\n';
    if (Params::PRINT_MATRIX) {
      std::cout << "Matrix of the best individual:" << '\n';
      std::cout << offspring[best].toString() << '\n';
    }

#pragma omp parallel for
    for (auto& f : offspring) {
      // MUTACIÓN
      if (Params::MUTATION_RATE > Helpers::randomDouble()) {
        unsigned int numGenesChanged = Helpers::randomInt(1, Params::MAX_GENES_CHANGED);
        for (unsigned int j = 0; j < numGenesChanged; j++) {
          auto mutationType = Helpers::randomInt(0, 8);
          switch (mutationType) {
            case 0:
              f.mutateEdges();
              break;

            case 1:
              f.mutateGains();
              break;

            case 2:
              f.mutateDelays();
              break;

            case 3:
              f.mutateReciprocal();
              break;

            case 4:
              f.mutateMerge(1);
              break;

            case 5:
              f.mutateMerge(2);
              break;

            case 6:
              f.mutateConsecutiveEdges();
              break;

            case 7:
              f.mutateMergeUsingLonelyNodeAsSink();
              break;

            default:  // 8
              f.mutateMergeUsingLonelyNodeAsSource();
              break;
          }
        }
      }
    }

#pragma omp parallel for
    for (unsigned int i = 0; i < Params::POPULATION_SIZE; i++) {
      population[i] = offspring[i];
    }

  } while (max_fitness_ever < Params::EXIT_THRESHOLD && countOfStalledGenerations < 1000 &&
           g < Params::MAX_GENERATIONS);

  return 0;
}
