#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <tuple>
#include <stack>


using namespace std;

class Rules{
private:
	int rooms[4][4];
	int room_id= 0;
	stack<int>okrooms;
	int row, col, num, size = 0;
	int adjacentRoom[4];
	int maxBorder = 3;
	int minBorder = 0;
	bool breez, stench, glitter, bump; 
	tuple<int, int>preAgentState = std::make_tuple(3, 0);
public:
	void buildEnvironment();
	void movement();
	bool isAdjacentRooms(int roomA, int roomB);
	int* findAdjacentRooms(int CurrentAgent);
	int getAgentCurrentPositionById(int room_id);
	void ruleMatch();
	bool models();
	int generateRandomNo(int lower, int upper);
	
};
 