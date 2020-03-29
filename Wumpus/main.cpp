#include <iostream>
#include <iomanip>
#include "coordinates.hpp"
#include "wumpusworld.hpp"


using namespace std;

int main()
{
	Coordinates coordinate(2, 1, SOUTH);
	World world;
	world.buildEnvironment();
	return 0;
};