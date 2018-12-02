cmake_minimum_required (VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project (AoC2018)

include_directories ("${PROJECT_BINARY_DIR}")

add_executable (Day1 day1/main.cpp)
add_executable (Day2 day2/main.cpp)

set (CMAKE_CXX_FLAGS_RELEASE_INIT "-O4 -DNDEBUG")

# target_link_libraries (DayX profiler)
# target_link_libraries (DayX tcmalloc)
