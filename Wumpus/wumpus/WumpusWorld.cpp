#include <iostream>
#include <iomanip>
#include <vector>
#include <new>
#include "wumpusworld.hpp"

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

using namespace std;

World::World(){}
/**	
 * creat an environment to the an agent
 * initialize parameters
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
	std::cout << "Adding a Pits..." << endl;
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
				pitsPosition[countNoPits] = Coordinates(row, col);
				pitsPosition[countNoPits].printDirction();
				rooms[row][col] = 'P';
				countNoPits+=1;
			}
			else
			{
				goto RowAndColOfPits;
			}
		}

		pits = true;
	}

	// add agent
	std::cout << "Adding an Agent..." << endl;
	agentPosition = Coordinates(3, 0);
	agentPosition.printDirction();
	rooms[3][0] = 'A';
	agent = true;

	//add gold
	std::cout << "Adding a Gold..." << endl;
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
			goldPosition = Coordinates(row, col);
			goldPosition.printDirction();
			rooms[row][col] = 'G';
		}
		else
		{
			goto RowAndColOfGold;
		}

		gold = true;
	}

	// add wumpus
	std::cout << "Adding a wumpus..." << endl;
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
			wumpusPosition = Coordinates(row, col);
			wumpusPosition.printDirction();
			rooms[row][col] = 'W';
		}
		else
		{
			goto RowAndColOfWumpus;
		}

		wumpus = true;
	}
}

/**
 * @return true if gold is taken by an agent
 */
bool World::goldtaken()
{
	return isGoldTaken;
}

/**
 * @return true if wumpus is killed by an agent  else false
 */
bool World::wumpusDead()
{
	return isWumpusDead;
}

/**
 * @return goldPosition from the cell
 */
Coordinates World::getGoldPosition()
{
	return goldPosition;	
}

/**
 * @return wumpusPosition from the cell
 */
Coordinates World::getWumpusPosition()
{
	return wumpusPosition;
}	

/**
 * @param index index of an array to loop through pits
 * @return pitsPosition[index] from the cell
 */
Coordinates World::getPitsPosition(int index)
{
	return pitsPosition[index];
}

void World::killWumpus()
{
	isWumpusDead = true;
}

void World::takeGold()
{
	isGoldTaken = true;
}

/**
 * @param playerPosition the position of an agent
 * @return  dangerZone which is vector of adjacent cells
 */
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

/**
 * @param playerPosition the position of an agent
 * @param mapElement the coordinates of an element 
 * @return true if they are adjacent else false
 */
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

/**
 * @param lower lower border of the environment
 * @param upper upper border of the environment
 * @return two dimensional coordinates
 */
int World::generateRandomNo(int lower, int upper)
{
	srand(time(0));
	return (rand() % (upper - lower + 1)) + lower;
}
