cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# add include directories
include_directories(../wumpus)

add_library(wumpus SHARED 
                  Coordinates.cpp
                  WumpusWorld.cpp
                  Percept.cpp
                  )

set_property(TARGET wumpus PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)
