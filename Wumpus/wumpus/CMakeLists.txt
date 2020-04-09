cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# creates the variable EXEC and sets it to main
#set(EXEC wumpus)

# add include directories
include_directories(../wumpus)

add_library(header SHARED Coordinates.cpp)

set_property(TARGET header PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)
