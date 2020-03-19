#include <iostream>
#include <iomanip>
#include <string>
#include <array>


using std::cout;
using std::endl;
using std::string;
using std::array;

class Rules{
private:
	char rooms[4][4];
public:
	void buildEnvironment();
	int generateRandomNo(int lower, int upper);
	
};