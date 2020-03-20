#include "../includes/wumpusWorld.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>
#include <tuple>
#include <cstdlib>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::tuple;

const static int adjacentRooms[24][2] = {
	{1, 5}, {1, 2}, {2, 3}, {2, 6}, {3, 7}, {3, 4},
	{4, 8}, {5, 9}, {5, 6}, {6, 7}, {6, 10}, {7, 8},
	{7, 11}, {8, 12}, {9, 13}, {9, 10}, {10, 11}, {10, 14},
	{11, 12}, {11, 15}, {12, 16}, {13, 14}, {14, 15}, {15, 16}
};

void Rules::buildEnvironment()
{
	 // initializing empty room except room(3,)
	for (int i = 0; i < 4; i++)
	{
		
		for (int j = 0; j < 4; j++)
		{	
			if (i == 3 and j == 0)
			{
				continue; // skip to the next row and col since i =3 and j =0 occupied by an Agent
			}

			rooms[i][j] = 0;	
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		adjacentRoom[i] = 0;
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
			num = this->generateRandomNo(1, 16);
			row = this->generateRandomNo(0, 3);
			col = this->generateRandomNo(0, 3);
		while(countNoPits < 3)
		{
			if (rooms[row][col] == 0)
			{
				rooms[row][col] = num;
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
	rooms[3][0] = 13;
	cout << "An agen is: " << rooms[3][0] << endl;
	agent = true;

	//add gold
	cout << "Adding a Gold..." << endl;
	RowAndColOfGold:
		num = this->generateRandomNo(1, 16);
		row = this->generateRandomNo(0, 3);
		col = this->generateRandomNo(0, 3);
	while(!gold)
	{
		if (rooms[row][col] == 0)
		{
			rooms[row][col] = num;
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
		num = this->generateRandomNo(1, 16);
		row = this->generateRandomNo(0, 3);
		col = this->generateRandomNo(0, 3);

	while(!wumpus)
	{
		if (rooms[row][col] == 0)
		{
			rooms[row][col] = num;
			cout <<"Wumpus is: " << rooms[row][col] <<endl;
		}
		else
		{
			goto RowAndColOfWumpus;
		}

		wumpus = true;
	}
}

int* Rules::findAdjacentRooms(int CurrentAgent)
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
bool Rules::isAdjacentRooms(int roomA, int roomB)
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

void Rules::movement()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; i < 11; j++)
		{
			if (i == 0 and j == 0)
			{	
				Okrooms[i][j] = rooms[3][0];
				continue;
			}
			Okrooms[i][j] = 0;
			if (j == 10)
			{
				break;
			}
		}
	}

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << adjacentRooms[i][j] << endl;
		}
	}
}

int Rules::generateRandomNo(int lower, int upper)
{
	srand(time(0));
	return (rand() % (upper - lower + 1)) + lower;
}

int main()
{
	Rules rule;
	rule.buildEnvironment();
	int* ad = rule.findAdjacentRooms(13);
	for (int i = 0; i < 4; i++)
	{
		if (*(ad + i) == 0)
		{
			continue;
		}

		cout << *(ad + i) << endl;
	}
	bool val = rule.isAdjacentRooms(13, 9);
	// rule.movement();
	return 0;
}
