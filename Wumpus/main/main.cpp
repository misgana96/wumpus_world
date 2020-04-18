#include <iostream>
#include <iomanip>
#include "and.hpp"
#include "or.hpp"
#include "wumpusworld.hpp"


using namespace Wumpus;
using namespace helper;
using namespace std;

int main()
{
	Coordinates coordinate(2, 1, SOUTH);
	World wr;
	wr.buildEnvironment();
	Coordinates pits =  wr.getPitsPosition(0);
	pits.printDirction();
	coordinate.getCol();
	coordinate.getRow();
	coordinate.getDirection();
	return 0;
};