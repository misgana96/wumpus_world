cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

#creates the ariable EXEC and sets it to main
SET(EXEC main)

# add include directories
include_directories(../wumpus)

# add executable files
add_executable(${EXEC} main.cpp)

target_link_libraries(${EXEC} header)
