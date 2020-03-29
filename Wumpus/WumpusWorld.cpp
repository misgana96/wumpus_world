#include <iostream>
#include <iomanip>

#include "coordinates.hpp"
#include "wumpusworld.hpp"



using namespace std;

const static int adjacentRooms[24][2] = {
	{1, 5}, {1, 2}, {2, 3}, {2, 6}, {3, 7}, {3, 4},
	{4, 8}, {5, 9}, {5, 6}, {6, 7}, {6, 10}, {7, 8},
	{7, 11}, {8, 12}, {9, 13}, {9, 10}, {10, 11}, {10, 14},
	{11, 12}, {11, 15}, {12, 16}, {13, 14}, {14, 15}, {15, 16}
};

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

			rooms[i][j] = 0; // empty room
			adjacentRoom[i] = 0;	// empty adjacent room to an agent
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
				piCoordinates *pitsPosition = new Coordinates(row, col);
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
	Coordinates *agentPosition = new Coordinates(row, col);
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
			Coordinates *goldPosition = new Coordinates(row, col);
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
			Coordinates *wumpusPosition = new Coordinates(row, col);
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
	return *this->goldPosition;
}

// finding an adjacent rooms to the current agent room
int* World::findAdjacentRooms(int CurrentAgent)
{
	for (int i = 0; i < 24; i++)
	{
		
		for (int j = 0; j < 2; j++)
		{
			if (adjacentRooms[i][j] == CurrentAgent)
			{

				if (j == 1)
				{
					adjacentRoom[size] = adjacentRooms[i][j - 1];
					size+=1;
				}
				else if (j == 0)
				{
					adjacentRoom[size] = adjacentRooms[i][j + 1];
					size+=1;
				}
			}
		}
	}

	return adjacentRoom;
}


// return anget coordinate 
int World::getAgentCurrentPositionById(int room_id)
{
	for(int i =0; i<4; i++)
	{
		for(int j=0;j<4;j++)
		{
			if(rooms[i][j] == room_id)
			{
				return i , j;
			}
		}
	}
}

// definition of models
bool World::models()
{
	// todo
}

// definition of rule match for the an agent to make action
void World::ruleMatch()
{
	bool shoot = false;
	okrooms.push(13);
	okrooms.push(9);
	okrooms.push(14);
	int preAgentPosition = rooms[3][0];
	int* roomsAjacentToAgent = findAdjacentRooms(preAgentPosition);
	for (int i = 0; i < 4; i++)
	{
		if (*(roomsAjacentToAgent + i) == 0)
		{
			continue;
		}

		for (int j = 0; j < 4; j++)
		{
			for (int m = 0; m < 4; m++)
			{
				if (rooms[j][m] == *(roomsAjacentToAgent + i) and rooms[j][m] == 'W')
				{
					cout << "shoot" << endl;
				}
			}
		}

	}
}

bool World::checkIfAdjacent(int roomA, int roomB)
{
	for (int i = 0; i < 2; ++i)
	{
		if (adjacentRooms[roomA][i] == roomB)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int World::generateRandomNo(int lower, int upper)
{
	srand(time(0));
	return (rand() % (upper - lower + 1)) + lower;
}