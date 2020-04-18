#include <iostream>
#include <iomanip>
#include "percept.hpp"


/** program_Percept.cpp ---
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

/**
 * @param breeze true if there is pit in adjacent cell else  false
 * @param stench true if there is wumpus in adjacent cell else false
 * @param glitter true if there is gold in the cell else false
 * @param bump true if an agent collide with the cell
 * @param position it is position of an element
 */
Percept::Percept(bool breeze, bool stench, bool glitter, bool bump, Coordinates position)
{
    this->breeze = breeze;
    this->bump = bump;
    this->glitter = glitter;
    this->stench = stench;
    this->position = position;
};
