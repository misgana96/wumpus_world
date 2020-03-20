#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <tuple>


using std::cout;
using std::endl;
using std::string;
using std::array;
using std::tuple;

class Rules{
private:
	int rooms[4][4];
	char Okrooms[1][11];
	//char adjacentRoom[4][2];
	int row, col, num, size = 0;
	int adjacentRoom[4];
	int maxBorder = 3;
	int minBorder = 0;
	tuple<int, int>preAgentState = std::make_tuple(3, 0);
public:
	void buildEnvironment();
	void movement();
	bool isAdjacentRooms(int roomA, int roomB);
	int* findAdjacentRooms(int CurrentAgent);
	int generateRandomNo(int lower, int upper);
	
};
 