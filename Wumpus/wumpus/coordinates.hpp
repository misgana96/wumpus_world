#include <iostream>
#include <iomanip>
#include <cstddef>
#include <string>


/** program_coordinates.hpp ---
*
*
* Authors: Misgana <misganayoseph@gmail.com> and Elias Tsegaw<tsegawelias@gmail.com>
* Copyright (c) 2020 misgana96
* This program is free software; you can redistribute it and/or modify
* it under the terms of the  MIT License as
* published by the Free Software Foundation
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* MIT License for more details.
*
* You should have received a copy of the MIT License
* along with this program; if not, write to:
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

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
    Coordinates();
    Coordinates(Coordinates &point);
    Coordinates(int row, int col, Directions direction);
    Coordinates(int row, int col);
    int getRow();
    int getCol();
    Directions getDirection();
    Coordinates moveEast();
    Coordinates moveWest();
    Coordinates moveNorth();
    Coordinates moveSouth();
    Coordinates moveAhead();
    Directions determineDirection(Coordinates end);
    void printDirction();
};

