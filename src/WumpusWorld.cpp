#include "../includes/wumpusWorld.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;

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

	// before pits, gold, agent, wumpus are intialized
	bool wumpus = false;
	bool agent = false;
	bool gold = false;
	bool pits = false;

	int row, col;
	
	// add pits
	cout << "Adding a Pits..." << endl;
	while(!pits)
	{
		int countNoPits = 0;
		RowAndColOfPits:
			row = this->generateRandomNo(0, 3);
			col = this->generateRandomNo(0, 3);
		while(countNoPits < 3)
		{
			if (rooms[row][col] == 0)
			{
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
	rooms[3][0] = 'A';
	cout << "An agen is: " << rooms[3][0] << endl;
	agent = true;

	//add gold
	cout << "Adding a Gold..." << endl;
	RowAndColOfGold:
		row = this->generateRandomNo(0, 3);
		col = this->generateRandomNo(0, 3);
	while(!gold)
	{
		if (rooms[row][col] == 0)
		{
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

	while(!wumpus)
	{
		if (rooms[row][col] == 0)
		{
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

int Rules::generateRandomNo(int lower, int upper)
{
	srand(time(0));
	return (rand() % (upper - lower + 1)) + lower;
}

int main()
{
	Rules rule;
	rule.buildEnvironment();
	return 0;
}