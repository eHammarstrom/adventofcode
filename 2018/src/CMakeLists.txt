cmake_minimum_required (VERSION 3.4)

project (AoC2018)

configure_file (
  "${PROJECT_SOURCE_DIR}/Config.h.cmake"
  "${PROJECT_BINARY_DIR}/Config.h"
  )

include_directories("${PROJECT_BINARY_DIR}")

add_executable (Day1 day1/main.cpp)
