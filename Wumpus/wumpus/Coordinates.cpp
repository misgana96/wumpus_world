#include <iostream>
#include <iomanip>
#include "coordinates.hpp"


using namespace std;

/**
 * check if it's an instance object of a a given constructor and 
 * it returns a boolean
 */
template<typename Base, typename T>
inline bool instanceof(const T*)
{
    return is_base_of<Base, T>::value;
}

/**
 * default constractuor
 */
Coordinates::Coordinates(){}

/**
 * Copy constructor
 * @param point the reference for the constructor Coordinates
 */
Coordinates::Coordinates(Coordinates& point)
{
    row = point.row;
    col = point.col;
    if(point.direction != 0)
    {
        direction = point.direction;
    }
}

/**
 * a constructor with parameters
 * @param row the row of the cell
 * @param col the row of the cell
 * @param direction the direction of the an agent
 */
Coordinates::Coordinates(int row, int col, Directions direction)
{
    this->row = row;
    this->col = col;
    this->direction = direction;
}

Coordinates::Coordinates(int row, int col)
{
    this->row = row;
    this->col = col;
}

/**
 * @return row of the cell
 */
int Coordinates::getRow()
{
    return row;
}

/**
 * @return col of the cell
 */
int Coordinates::getCol()
{
    return col;
}

/**
 * @return direction 
 */
Directions Coordinates::getDirection()
{
    return direction;
}

/**
 * @return *this which is a pointer type Coordinates
 */
Coordinates Coordinates::moveEast()
{
    col +=1;
    direction = EAST;
    return *this;
}

Coordinates Coordinates::moveWest()
{
    col -=1;
    direction = WEST;
    return *this;
}

Coordinates Coordinates::moveNorth()
{
    row -= 1;
    direction = NORTH;
    return *this;
}

Coordinates Coordinates::moveSouth()
{
    row += 1;
    direction = SOUTH;
    return *this;
}

Coordinates Coordinates::moveAhead()
{
    switch (direction)
    {
        case NORTH:
            moveNorth();
            break;
        case SOUTH:
            moveSouth();
            break;
        case EAST:
            moveEast();
            break;
        case WEST:
            moveWest();
            break;
        default:
            break;    
    }
    return *this;
}

/**
 * @param end which is type of Coordinates
 * @return direction 
 */
Directions Coordinates::determineDirection(Coordinates end)
{
    int startRow = 1;
    int startCol = 2;

    int endRow = end.getRow();
    int endCol = end.getCol();

    if(endCol == startCol -1)
    {
        return WEST;
    }
    else if(endCol == startCol + 1)
    {
        return EAST;
    }
    else if(endRow == startRow + 1)
    {
        return SOUTH;
    }
    else if(endRow == startRow - 1)
    {
        return NORTH;
    }

    return NONE;
}

void Coordinates::printDirction()
{
    cout << "(" << row <<"," << col <<","<< direction<<")"<<endl;
}
