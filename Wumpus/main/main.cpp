#include <iostream>
#include <iomanip>
#include "not.hpp"
#include "and.hpp"
#include "or.hpp"
#include "implication.hpp"
#include "bi_implication.hpp"
#include "Levaluate.hpp"

using namespace Wumpus;
using namespace Wumpus::helper;
using namespace Wumpus::util;
using namespace std;

int main()
{
	Levaluate ev;
    string propo1 = "p not ,F";
    string propo = "p r k and and not ,T T T";
    bool result = ev.eval(propo);
    bool result1 = ev.eval(propo1);
    cout << result << " " << result1<<endl;
    return 0;
};
