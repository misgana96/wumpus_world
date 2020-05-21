#include <cxxtest/TestSuite.h>
#include <iostream>
#include <iomanip>
#include "../../Wumpus/wumpus/wumpusworld.hpp"

using namespace std;

class TestCoordinates: public Coordinates
{
public:
    TestCoordinates():Coordinates(3, 0, SOUTH){}
};

class CoordinatesSuite : public CxxTest::TestSuite
{
public:

    Coordinates cr;
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

class WumpusWorldSuite : public CxxTest::TestSuite
{
public:

    World wr;

    /**
     * testing on initializing wumpus world 
     */
    void test_wumpus()
    {
        wr.buildEnvironment();

    }

    /**
     * @return true if gold is taken by an agent
     */
    void test_goldIsTaken()
    {
        
        bool gt = wr.goldtaken();
        TS_ASSERT_EQUALS(gt, false);

    }

    /**
     * @return true if wumpus is dead else false
     */
    void test_wumpusIsDead()
    {
        bool wd = wr.wumpusDead();
        TS_ASSERT_EQUALS(wd, false);

    }

    /**
     * @return goldPosition from the cell
     */
    void test_getGoldPosition()
    {
        Coordinates goldPosition = wr.getGoldPosition();
        goldPosition.printDirction();
    }

    /**
     * @return wumpusPosition from the cell
     */
    void test_getWumpusPosition()
    {
        Coordinates wumpusPosition = wr.getWumpusPosition();
        wumpusPosition.printDirction();
    }

    /**
     * @param index index of an array to loop through pits
     * @return pitsPosition[index] from the cell
     */
    void test_getPitsPosition()
    {
        Coordinates pitsPosition = wr.getPitsPosition(0);
        pitsPosition.printDirction();

    }

    /**
     * @param playerPosition which is position of an agent
     * @return  dangerZone which is vector of adjacent cells
     */
    void test_getAdjacentCell()
    {
        Coordinates playerPosition(3, 0);
        vector<Coordinates>::iterator it;
        vector<Coordinates>cells = wr.getAdjacentCells(playerPosition);
        for (int i= 0; i < cells.size(); i++)
        {
            cells.at(i).printDirction();
        }
              
    }

    /**
     * @param playerPosition the position of an agent
     * @param mapElement the position of an element which is either wumpus, pits
     * @return true if they are adjacent else false
     */
    void test_isAdjacent()
    {
        Coordinates playerPosition(3, 0);
        Coordinates wumpusPosition(3, 1);
        bool Adj = wr.checkIfAdjacent(playerPosition, wumpusPosition);
        TS_ASSERT_EQUALS(Adj, true);
    }

    /**
     * @param lower which is lowest border of the env
     * @param higher which is highest border of the env
     * @return row and col of the rooms
     */
    void test_generateRandomNo()
    {
        int cor = wr.generateRandomNo(0, 3);
    }

};
