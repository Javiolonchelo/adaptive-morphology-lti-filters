#include "Algorithm.h"

void incorrectUsage(char* argv[]) {
  std::cerr << "Error. Invalid arguments." << std::endl
            << std::endl
            << "Usage: " << std::endl
            << " - Dereverb          " << argv[0] << " 0" << std::endl
            << " - Filter modelling  " << argv[0] << " 1 <FILTER_NAME> <OUTPUT_FILE>" << std::endl
            << " - Denoise           " << argv[0] << " 2" << std::endl;
}

int main(int argc, char* argv[]) {
  unsigned int        L = 2048;
  std::vector<double> inputSignal;
  std::vector<double> target;
  int                 mode = -1;

  std::string filterName;
  std::string outputFile;

  srand(time(NULL));
  // omp_set_schedule(omp_sched_static, 0);  // Commented out for MSVC compatibility
  omp_set_num_threads(Params::NUM_THREADS);

  if (argc < 2) {
    incorrectUsage(argv);
    return 1;
  }

  mode = atoi(argv[1]);
  switch (mode) {
    case 0:  // TODO Dereverb
      break;

    case 1:  // Filter finder
      if (argc != 4) {
        incorrectUsage(argv);
        return 1;
      }
      filterName = argv[2];
      outputFile = argv[3];
      break;

    case 2:  // TODO Generic ideal output
      break;

    default:
      incorrectUsage(argv);
      return 1;
  }

  if (Menu(inputSignal, target, L, filterName, outputFile, mode)) return 1;

  if (Algorithm(inputSignal, target, L, outputFile)) return 1;

  return 0;
}
