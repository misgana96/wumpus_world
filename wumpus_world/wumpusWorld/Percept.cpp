#include <iostream>
#include <iomanip>
#include "coordinates.hpp"
#include "percept.hpp"


using namespace std;

Percept::Percept(bool breeze, bool stench, bool glitter, bool bump, Coordinates position)
{
    this->breeze = breeze;
    this->bump = bump;
    this->glitter = glitter;
    this->stench = stench;
    this->position = position;
};
