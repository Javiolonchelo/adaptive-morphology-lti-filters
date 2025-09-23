cmake_minimum_required(VERSION 3.10.0)

project(
  PFG
  VERSION 1.0.0
  LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# COMPILER FLAGS 
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")
if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2")
    # MSVC compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
    # GCC/Clang compiler flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wwrite-strings")
endif()

# Set LSAN_OPTIONS for all targets (for debugging memory leaks)
set(ENV{LSAN_OPTIONS} "verbosity=1:log_threads=1")

# DEPENDENCIES
# OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    message(STATUS "OpenMP found")
    if(MSVC)
        # For MSVC, OpenMP is built-in, just need to enable it
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /openmp")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    endif()
else()
    message(FATAL_ERROR "OpenMP not found")
endif()

# jsoncpp + common sources
add_library(PFG_common STATIC "src/Filter.cpp" "src/Parameters.cpp"
                              "ext/jsoncpp/jsoncpp.cpp")
target_include_directories(PFG_common PUBLIC "${CMAKE_SOURCE_DIR}/ext/jsoncpp/")

# DOCUMENTATION WITH DOXYGEN
find_package(Doxygen OPTIONAL_COMPONENTS dot)
if(DOXYGEN_FOUND)
    message(STATUS "Doxygen found: ${DOXYGEN_EXECUTABLE}")
    add_custom_target(
      doc
      COMMAND ${DOXYGEN_EXECUTABLE} "${CMAKE_SOURCE_DIR}/doc/Doxyfile"
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/doc/html/index.html" "${CMAKE_SOURCE_DIR}/index.html"
      WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
      COMMENT "Generating API documentation with Doxygen")
else()
    message(STATUS "Doxygen not found. Documentation target will not be available.")
endif()

# MAIN PROGRAM 
add_executable(${PROJECT_NAME} "src/main.cpp" "src/Algorithm.cpp"
                               "src/Menu.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE PFG_common)
if(OpenMP_CXX_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE OpenMP::OpenMP_CXX)
endif()

# TESTS
add_executable(test "test/Tests.cpp")
target_include_directories(test PRIVATE "${CMAKE_SOURCE_DIR}/src"
                                        "${CMAKE_SOURCE_DIR}/ext/jsoncpp/")
target_link_libraries(test PRIVATE PFG_common)
if(OpenMP_CXX_FOUND)
    target_link_libraries(test PRIVATE OpenMP::OpenMP_CXX)
endif()
