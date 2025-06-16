#include <json/json.h>

#include "Filter.h"

Filter loadFilterFromJson(const std::string& filename);

void testMutateEdges();
void testMutateGains();
void testMutateDelays();
void testMutateReciprocal();
void testMutateMerge(unsigned int type);
void testMutateConsecutiveEdges();
void testmutateMergeUsingLonelyNodeAsSink();
void testmutateMergeUsingLonelyNodeAsSource();

void random(Filter& f) {
  const auto randomInt = [](int min = 0, int max = INT_MAX) {
    return std::rand() % (max - min + 1) + min;
  };
  switch (randomInt(0, 10))  // Randomly choose a case
  {
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
      f.mutateGains();
      break;
  }
}

int main() {
  // testMutateEdges();
  // testMutateGains();
  // testMutateDelays();
  // testMutateReciprocal();
  // testMutateMerge(1);
  // testMutateMerge(2);
  // testMutateConsecutiveEdges();
  // testmutateMergeUsingLonelyNodeAsSink();
  // testmutateMergeUsingLonelyNodeAsSource();
  // Filter f(Params::N);

  // for (unsigned int k = 0; k < 10000000; k++) {
  //   std::cout << "Testing mutation of edges in filter " << k << std::endl;

  //   random(f);
  //   for (unsigned int i = 0; i < Params::N; i++) {
  //     for (unsigned int j = 0; j < Params::N; j++) {
  //       if (f.type_layer[i][j] == 1) {
  //         assert(i < j);
  //       } else if (f.type_layer[i][j] == 2) {
  //         // float dummy;
  //         assert(f.value_layer[i][j] > 0);
  //         assert(std::modf(f.value_layer[i][j], &dummy) == 0.0);
  //       }
  //     }
  //   }
  // }
  return 0;
}

// IMPLEMENTACIÓN

Filter loadFilterFromJson(const std::string& filename) {
  Json::Value   json;
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Could not open file: " + filename);
  }
  file >> json;
  file.close();
  return Filter(json);
}

void testMutateEdges() {
  std::cout << "##################### mutateEdges #####################"
            << std::endl;
  auto f = loadFilterFromJson("../test/testMutateEdges.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateEdges();
  std::cout << "After mutateEdges:" << std::endl << f.toString() << std::endl;
}

void testMutateGains() {
  std::cout << "##################### mutateGains #####################"
            << std::endl;
  auto f = loadFilterFromJson("../test/testMutateGains.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateGains();
  std::cout << "After mutateGains:" << std::endl << f.toString() << std::endl;
}

void testMutateDelays() {
  std::cout << "##################### mutateDelays #####################"
            << std::endl;
  auto f = loadFilterFromJson("../test/testMutateDelays.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateDelays();
  std::cout << "After mutateDelays:" << std::endl << f.toString() << std::endl;
}

void testMutateReciprocal() {
  std::cout << "##################### mutateReciprocal #####################"
            << std::endl;
  auto f = loadFilterFromJson("../test/testMutateReciprocal.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateReciprocal();
  std::cout << "After mutateReciprocal:" << std::endl
            << f.toString() << std::endl;
}

void testMutateMerge(unsigned int type) {
  std::cout << "##################### mutateMerge (type " << type
            << ") #####################" << std::endl;
  auto f = loadFilterFromJson("../test/testMutateMerge" + std::to_string(type) +
                              ".json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateMerge(type);
  std::cout << "After mutateMerge:" << std::endl << f.toString() << std::endl;
}

void testMutateConsecutiveEdges() {
  std::cout
      << "##################### mutateConsecutiveEdges #####################"
      << std::endl;
  auto f = loadFilterFromJson("../test/testMutateConsecutiveEdges.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateConsecutiveEdges();
  std::cout << "After mutateConsecutiveEdges:" << std::endl
            << f.toString() << std::endl;
}

void testmutateMergeUsingLonelyNodeAsSink() {
  std::cout << "##################### mutateMergeUsingLonelyNodeAsSink "
               "#####################"
            << std::endl;
  auto f =
      loadFilterFromJson("../test/testMutateMergeUsingLonelyNodeAsSink.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateMergeUsingLonelyNodeAsSink();
  std::cout << "After mutateMergeUsingLonelyNodeAsSink:" << std::endl
            << f.toString() << std::endl;
}

void testmutateMergeUsingLonelyNodeAsSource() {
  std::cout << "##################### mutateMergeUsingLonelyNodeAsSource "
               "#####################"
            << std::endl;
  auto f =
      loadFilterFromJson("../test/testMutateMergeUsingLonelyNodeAsSource.json");
  std::cout << "Original filter:" << std::endl << f.toString() << std::endl;
  f.mutateMergeUsingLonelyNodeAsSource();
  std::cout << "After mutateMergeUsingLonelyNodeAsSource:" << std::endl
            << f.toString() << std::endl;
}