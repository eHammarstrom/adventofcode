cmake_minimum_required (VERSION 3.4)

project (AoC2018)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.cmake"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories ("${PROJECT_BINARY_DIR}")

add_executable (Day1 day1/main.cpp)

set (CMAKE_CXX_FLAGS_RELEASE_INIT "-O4 -DNDEBUG")

# target_link_libraries (Day1 profiler)
# target_link_libraries (Day1 tcmalloc)
