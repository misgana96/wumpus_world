#include <iostream>
#include <iomanip>
#include <tuple>
#include <stack>


using namespace std;

class World
{
private:
	char rooms[4][4];
	int room_id= 0;
	stack<int>okrooms;
	int row, col, num;
	int size = 0;
	int adjacentRoom[4];
	int maxBorder = 3;
	int minBorder = 0;
	bool breez, stench, glitter, bump;
	bool isGoldTaken = false;
	bool isWumpusDead = false;
	Coordinates *goldPosition;
	Coordinates *agentPosition;
	Coordinates *wumpusPosition;
	Coordinates *pitsPosition; 
	tuple<int, int>preAgentState = std::make_tuple(3, 0);
public:
	void buildEnvironment();
	bool goldtaken();
    bool wumpusDead();
	Coordinates getGoldPosition();
	void movement();
	bool checkIfAdjacent(int roomA, int roomB);
	int* findAdjacentRooms(int CurrentAgent);
	int getAgentCurrentPositionById(int room_id);
	void ruleMatch();
	bool models();
	int generateRandomNo(int lower, int upper);
	
};
 