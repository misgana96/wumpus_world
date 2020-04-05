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
 