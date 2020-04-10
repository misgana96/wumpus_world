#include <iostream>
#include <iomanip>
#include "coordinates.hpp"


using namespace std;

int main()
{
   Coordinates coordinates(2, 1, SOUTH)
   coordinates.getCol();
   coordinates.getRow();
   coordinates.getDirection();
   
   return 0;
}