cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# Add sub-directories
add_subdirectory(helper)
add_subdirectory(wumpus)
add_subdirectory(util)
add_subdirectory(main)