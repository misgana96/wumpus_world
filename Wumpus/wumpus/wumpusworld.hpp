#include "percept.hpp"
#include <iostream>
#include <iomanip>
#include <vector>

/** program_wumpusworld.hpp ---
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

class World
{
private:
	char rooms[4][4];
	int colCount = 3;
	int rowCount =3;
	int row, col, num, countNoPits;
	void killWumpus();
	void takeGold();
public:
	bool isGoldTaken = false;
	bool isWumpusDead = false;
	Coordinates pitsPosition[3] = {
					*new Coordinates(row, col),
					*new Coordinates(row, col),
					*new Coordinates(row, col)
					};
	Coordinates agentPosition;
	Coordinates goldPosition;
	Coordinates wumpusPosition; 
	World();
	vector<Coordinates> getAdjacentCells(Coordinates playerPosition);
	bool checkIfAdjacent(Coordinates playerPosition, Coordinates mapElement);
	void buildEnvironment();
	Percept getPercept(Coordinates playerPosition);
	bool goldtaken();
   	bool wumpusDead();
	Coordinates getGoldPosition();
	Coordinates getWumpusPosition();
	Coordinates getPitsPosition(int index);
	int generateRandomNo(int lower, int upper);
	
};
 