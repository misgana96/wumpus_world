cmake_minimum_required (VERSION 3.8)
project (WUMPUS_WORLD_CHALLANGE)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)


# add include directories
include_directories( ../../Wumpus/Wumpus)

set(CXXTEST_CURRENT_SOURCE_DIR)
find_package(CxxTest)
if(CXXTEST_FOUND)
    include_directories(/usr/include/)
    enable_testing()

    CXXTEST_ADD_TEST(wumpustest wumpusWorld.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/TestSuite.hpp)
<<<<<<< HEAD
    target_link_libraries(wumpustest wumpus)
=======
    target_link_libraries(wumpustest header)
>>>>>>> test

endif()
