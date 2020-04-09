#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include "coordinates.hpp"

using namespace std;

class TestCoordinates: public Coordinates
{
public:
    TestCoordinates():Coordinates(3, 0, SOUTH){}
};

class CoordinatesSuite : public CxxTest::TestSuite
{
public:
    /**
     * which tests row of the cell
     */
    void test_getRow()
    {
        int row = TestCoordinates().getRow();
        TS_ASSERT_EQUALS(3, row);
    }

    /**
     * which tests col of the cell
     */
    void test_getCol()
    {
        int col = TestCoordinates().getCol();
        TS_ASSERT_EQUALS(0, col);
    }

    /**
     * which test direction of the cell
     */
    void test_getDirection()
    {
        Directions dir = TestCoordinates().getDirection();
        TS_ASSERT_EQUALS(SOUTH, dir);
    }

    /**
     * print out the the coordinates with direction
     */
    void Test_printDirction()
    {
        TestCoordinates().printDirction();
        TS_ASSERT((3, 0, SOUTH));
    }
};
