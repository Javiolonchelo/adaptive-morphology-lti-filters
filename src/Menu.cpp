#include "Menu.h"

int Menu(std::vector<double>& inputSignal,
         std::vector<double>& targetTime,
         unsigned int&        L,
         std::string          filterName = "",
         std::string outputFile          = "output/results",
         int mode                        = -1) {
  std::fstream        file;
  std::vector<double> desired_b, desired_a;

  switch (mode) {
    case 0: {
      return 1;
      break;
    }

    case 1: {
      file.open("../../data/filters_for_benchmarking.csv", std::ios::in);
      if (!file.good()) {
        std::cerr << "Error al abrir la base de datos '../../data/filters_for_benchmarking.csv'." << std::endl;
        return 1;
      }
      std::string                            line;
      std::vector<std::vector<std::string> > parsedCsv;
      while (std::getline(file, line)) {
        std::stringstream        lineStream(line);
        std::string              cell;
        std::vector<std::string> parsedRow;
        while (std::getline(lineStream, cell, ';')) {
          parsedRow.push_back(cell);
        }
        parsedCsv.push_back(parsedRow);
      }
      file.close();
      for (auto& row : parsedCsv) {
        if (!row.empty() && row[0] == filterName) {
          std::string       b = row[1].substr(1, row[1].size() - 2);
          std::string       a = row[2].substr(1, row[2].size() - 2);
          std::stringstream ss;
          std::string       token;
          ss = std::stringstream(b);
          while (std::getline(ss, token, ','))
            desired_b.push_back(std::stod(token));
          ss = std::stringstream(a);
          while (std::getline(ss, token, ','))
            desired_a.push_back(std::stod(token));
          break;
        }
      }

      inputSignal.resize(L);

      Helpers::createSignal(inputSignal, Params::inputSignal_TYPE, L);
      Helpers::filterUsingDifferenceEquation(inputSignal, targetTime, desired_b, desired_a, L);

      Json::Value jsonOutput;
      for (unsigned int i = 0; i < desired_b.size(); i++) {
        jsonOutput["b"][i] = desired_b[i];
        jsonOutput["a"][i] = desired_a[i];
      }

      for (unsigned int i = 0; i < L; i++) {
        jsonOutput["Target"][i] = targetTime[i];
      }

      std::string targetFilterFile = outputFile.substr(0, outputFile.size() - 4) + "-TARGET.json";
      file.open(targetFilterFile, std::ios::trunc | std::ios::out);
      if (file.is_open()) {
        file << jsonOutput.toStyledString();
        file.close();
      } else {
        std::cerr << "Error al abrir el archivo JSON de salida." << std::endl;
        return 1;
      }

      break;
    }
    case 2: {  // TODO
      break;
    }
  }

  return 0;
}
