cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

# creates the variable EXEC and sets it to main
set(EXEC main)

# add include directories
include_directories(../Wumpus)

# add executable files
add_executable(${EXEC}
                        WumpusWorld.cpp
                        Coordinates.cpp
                        main.cpp
)

set_property(TARGET ${EXEC} PROPERTY POSITION_INDEPENDENT_CODE ON)

add_library(header SHARED 
                            WumpusWorld.cpp
                            Coordinates.cpp
)

set_property(TARGET header PROPERTY INTERFACE_POSITION_INDEPENDENT_CODE ON)

target_link_libraries(${EXEC} header)