cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# add include directories
include_directories(../helper)

add_library(helper SHARED 
                  and.cpp
                  or.cpp
                  implication.cpp
                  )

set_property(TARGET helper PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)
