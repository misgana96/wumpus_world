#include <iostream>
#include <iomanip>


using namespace std;

class Percept
{
private:
    bool stench;
    bool breeze;
    bool glitter;
    bool bump;
    Coordinates position;

public:
    Percept(bool breeze, bool stench, bool glitter, bool bump, Coordinates position);
};