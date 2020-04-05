#include <iostream>
#include <iomanip>
#include "coordinates.hpp"

using namespace std;

template<typename Base, typename T>
inline bool instanceof(const T*)
{
    return is_base_of<Base, T>::value;
}

Coordinates::Coordinates(){}

Coordinates::Coordinates(Coordinates& point)
{
    row = point.row;
    col = point.col;
    if(point.direction != 0)
    {
        direction = point.direction;
    }
}

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

int Coordinates::getRow()
{
    return row;
}

int Coordinates::getCol()
{
    return col;
}

Directions Coordinates::getDirection()
{
    return direction;
}

bool Coordinates::equals(Object *obj)
{
    if (this == obj)
    {
        return true;
    }
    else if (instanceof<Coordinates>(obj))
    {
        Coordinates other = (Coordinates)*obj;
        if (row == other.getRow() and col == other.getCol())
        {
            return true;
        }
        
    }

    return false;
    
}

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
