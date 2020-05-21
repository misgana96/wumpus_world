cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# creates the variable EXEC and sets it to main
set(EXEC unittest)

# add include directories
include_directories( ../../Wumpus/helper)
include_directories( ../../Wumpus/wumpus)
include_directories(../wumpus ../helper)

# add executable files
add_executable(${EXEC} main.cpp)

#target_link_libraries(${EXEC} wumpustestunittest helpertestunittest)
