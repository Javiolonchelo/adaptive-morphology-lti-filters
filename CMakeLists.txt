cmake_minimum_required(VERSION 3.10.0)

project(
  PFG
  VERSION 1.0.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# COMPILER FLAGS 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

# General warnings and OpenMP for all builds
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wwrite-strings -fopenmp")

# Set LSAN_OPTIONS for all targets (for debugging memory leaks)
set(ENV{LSAN_OPTIONS} "verbosity=1:log_threads=1")

# DEPENDENCIES
# OpenMP
find_package(OpenMP REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")

# jsoncpp + common sources
add_library(PFG_common STATIC "src/Filter.cpp" "src/Parameters.cpp"
                              "ext/jsoncpp/jsoncpp.cpp")
target_include_directories(PFG_common PUBLIC "${CMAKE_SOURCE_DIR}/ext/jsoncpp/")

# DOCUMENTATION WITH DOXYGEN
find_package(Doxygen REQUIRED dot)
message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE}")
add_custom_target(
  doc
  COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_SOURCE_DIR}/doc/Doxyfile"
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/doc/html/index.html" "${CMAKE_SOURCE_DIR}/index.html"
  WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
  COMMENT "Generating API documentation with Doxygen")

# MAIN PROGRAM 
add_executable(${PROJECT_NAME} "src/main.cpp" "src/Algorithm.cpp"
                               "src/Menu.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE PFG_common OpenMP::OpenMP_CXX)

# TESTS
add_executable(test "test/Tests.cpp")
target_include_directories(test PRIVATE "${CMAKE_SOURCE_DIR}/src"
                                        "${CMAKE_SOURCE_DIR}/ext/jsoncpp/")
target_link_libraries(test PRIVATE PFG_common OpenMP::OpenMP_CXX)
