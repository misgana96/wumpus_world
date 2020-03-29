#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>

using namespace std;

enum Directions
{
    NORTH,
    SOUTH,
    WEST,
    EAST,
    NONE
};

class Coordinates
{
private:
    int row;
    int col;

public:
    Directions direction;
    Coordinates(Coordinates &point);
    Coordinates(int row, int col, Directions direction);
    Coordinates(int row, int col);
    int getRow();
    int getCol();
    Directions getDirection();
    Coordinates &moveEast();
    Coordinates &moveWest();
    Coordinates &moveNorth();
    Coordinates &moveSouth();
    Coordinates &moveAhead();
    Directions determineDirection(Coordinates end);
    void printDirction();
};