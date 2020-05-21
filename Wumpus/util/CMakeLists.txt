cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# add include directories
include_directories(../helper ../util)

add_library(util SHARED 
                  L_proposition.cpp
                  forwardL_parser.cpp
                  #reverseL_parser.cpp
                  statment.cpp
                  Levaluate.cpp
                  )

set_property(TARGET util PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)

target_link_libraries(util helper)

