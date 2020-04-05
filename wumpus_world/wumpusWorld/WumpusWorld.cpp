/** program_WumpusWorld.cpp ---
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

#include "coordinates.hpp"
#include "percept.hpp"
#include "wumpusworld.hpp"



using namespace std;

/*	
	set room id for each room and
	creat an environment to the an agent
*/
void World::buildEnvironment()
{
	 // initializing empty room except room(3,0) and adjacent room to an agent
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{	
			if (i == 3 and j == 0)
			{
				continue; // skip to the next row and col since i =3 and j =0 occupied by an Agent
			}

			rooms[i][j] = 0; // empty rooms
		}
	}

	// before pits, gold, agent, wumpus are intialized
	bool wumpus = false;
	bool agent = false;
	bool gold = false;
	bool pits = false;
	
	// add pits
	cout << "Adding a Pits..." << endl;
	while(!pits)
	{
		int countNoPits = 0;
		RowAndColOfPits:
			row = this->generateRandomNo(0, 3);
			col = this->generateRandomNo(0, 3);

		// make sure that room(2, 0) and room(3, 1) free from danger
		if ((row == 2 and col == 0) or (row == 3 and col == 1))
		{
			goto RowAndColOfPits;
		}

		while(countNoPits < 3)
		{
			if (rooms[row][col] == 0)
			{
				Coordinates pitsPosition[countNoPits] = *new Coordinates(row, col);
				rooms[row][col] = 'P';
				countNoPits+=1;
				cout << countNoPits << ":" << rooms[row][col] <<endl;
			}
			else
			{
				goto RowAndColOfPits;
			}
		}

		pits = true;
	}

	// add agent
	cout << "Adding an Agent..." << endl;
	Coordinates agentPosition = *new Coordinates(row, col);
	rooms[3][0] = 'A';
	cout << "An agen is: " << rooms[3][0] << endl;
	agent = true;

	//add gold
	cout << "Adding a Gold..." << endl;
	RowAndColOfGold:
		row = this->generateRandomNo(0, 3);
		col = this->generateRandomNo(0, 3);

	// make sure that room(2, 0) and room(3, 1) free from danger
	if ((row == 2 and col == 0) or (row == 3 and col == 1))
		{
			goto RowAndColOfGold;
		}

	while(!gold)
	{
		if (rooms[row][col] == 0)
		{
			Coordinates goldPosition = *new Coordinates(row, col);
			rooms[row][col] = 'G';
			cout <<"Gold is: " << rooms[row][col] <<endl;
		}
		else
		{
			goto RowAndColOfGold;
		}

		gold = true;
	}

	// add wumpus
	cout << "Adding a wumpus..." << endl;
	RowAndColOfWumpus:
		row = this->generateRandomNo(0, 3);
		col = this->generateRandomNo(0, 3);

	// make sure that room(2, 0) and room(3, 1) free from danger
	if ((row == 2 and col == 0) or (row == 3 and col == 1))
		{
			goto RowAndColOfWumpus;
		}

	while(!wumpus)
	{
		if (rooms[row][col] == 0)
		{
			Coordinates wumpusPosition = *new Coordinates(row, col);
			rooms[row][col] = 'W';
			cout <<"Wumpus is: " << rooms[row][col] <<endl;
		}
		else
		{
			goto RowAndColOfWumpus;
		}

		wumpus = true;
	}
}

bool World::goldtaken()
{
	return isGoldTaken;
}

bool World::wumpusDead()
{
	return isWumpusDead;
}

Coordinates World::getGoldPosition()
{
	return goldPosition;	
}

Coordinates World::getWumpusPosition()
{
	return wumpusPosition;
}	

Coordinates World::getPitsPosition(int index)
{
	return pitsPosition[index];
}

Percept World::getPercept(Coordinates playerPosition)
{
	bool hasStench = false;
	bool hasGlitter = false;
	bool hasBump = false;
	bool hasBreeze = false;
	for (int i = 0; i < sizeof(pitsPosition); i++)
	{
		hasBreeze = checkIfAdjacent(playerPosition, pitsPosition[i]);
		if (hasBreeze)
		{
			break;
		}
		
		hasStench = checkIfAdjacent(playerPosition, wumpusPosition) and !isWumpusDead;
		hasGlitter = playerPosition.equals(goldPosition);
		hasBump = checkBump(playerPosition);

		return *new Percept(hasBreeze, hasStench, hasGlitter, hasBump, playerPosition);
	}
}

void World::killWumpus()
{
	isWumpusDead = true;
}

void World::takeGold()
{
	isGoldTaken = true;
}

vector<Coordinates> World::getAdjacentCells(Coordinates playerPosition)
{
	vector<Coordinates> dangerZoneList;

	int playerRow = playerPosition.getRow();
	int playerCol = playerPosition.getCol();

	if(playerCol - 1 >= 0)
	{
		Coordinates westcell(playerRow, playerCol - 1);
		dangerZoneList.push_back(westcell);
	}
	if (playerCol + 1 <= 3)
	{
		Coordinates eastcell(playerRow, playerCol + 1);
		dangerZoneList.push_back(eastcell);
	}
	if (playerRow - 1 >= 0)
	{
		Coordinates northcell(playerRow - 1, playerCol);
		dangerZoneList.push_back(northcell);
	}
	if (playerRow + 1 <= 3)
	{
		Coordinates southcell(playerCol + 1, playerCol);
		dangerZoneList.push_back(southcell);
	}
	
	return dangerZoneList;
	
}

bool World::checkIfAdjacent(Coordinates playerPosition, Coordinates mapElement)
{
	bool isAdjacent = false;

	int playerRow = playerPosition.getRow();
	int playerCol = playerPosition.getCol();

	int elementRow = mapElement.getRow();
	int elementCol = mapElement.getCol();

    if (playerRow == elementRow && ( playerCol == elementCol - 1 || playerCol == elementCol + 1)) 
	{
    	return true;
	}
	else if (playerCol == elementCol && ( playerRow == elementRow - 1 || playerRow == elementRow + 1 )) 
	{
		return true;
	}

	return isAdjacent;	
}

bool World::checkBump(Coordinates playerPosition)
{
	bool hasBump = false;

	int playerRow = playerPosition.getRow();
	int playerCol = playerPosition.getCol();

	Directions direction = playerPosition.getDirection();

	if ( playerRow < 0 || playerRow > 3 || playerCol < 0 || playerCol > 3) 
	{
		hasBump = true;
		return hasBump;
	}
	if (direction == EAST and playerCol > 3)
	{
		hasBump = true;
		return hasBump;
	}
	if (direction == WEST and playerCol < 0 )
	{
		hasBump = true;
		return hasBump;
	}
	if (direction == SOUTH and playerRow > 3)
	{
		hasBump = true;
		return hasBump;
	}
	if (direction == NORTH and playerRow < 0)
	{
		hasBump = true;
		return hasBump;
	}

}

// generating random numbers
int World::generateRandomNo(int lower, int upper)
{
	srand(time(0));
	return (rand() % (upper - lower + 1)) + lower;
}
