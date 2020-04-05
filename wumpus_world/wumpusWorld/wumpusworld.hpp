/** program_wummpusworld.hpp ---
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

#include <iostream>
#include <iomanip>
#include <vector>


using namespace std;

class World
{
private:
	char rooms[4][4];
	int colCount = 3;
	int rowCount =3;
	int row, col, num, countNoPits;
	bool isGoldTaken = false;
	bool isWumpusDead = false;
	Coordinates goldPosition;
	Coordinates agentPosition;
	Coordinates wumpusPosition;
	Coordinates pitsPosition[]; 
	bool checkIfAdjacent(Coordinates playerPosition, Coordinates mapElement);
	bool checkBump(Coordinates playerPosition);
	void killWumpus();
	void takeGold();
	vector<Coordinates> getAdjacentCells(Coordinates playerPosition);
public:
	void buildEnvironment();
	bool goldtaken();
    bool wumpusDead();
	Coordinates getGoldPosition();
	Coordinates getWumpusPosition();
	Coordinates getPitsPosition(int index);
	Percept getPercept(Coordinates playerPosition);
	int generateRandomNo(int lower, int upper);
	
};
 