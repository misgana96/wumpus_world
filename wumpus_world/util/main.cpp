#include "Levaluate.hpp"
#include <string>
using namespace wumpus_world;
using namespace util;
using namespace std;
int main(){
    Levaluate ev;
    string propo1 = "p not ,F";
    string propo = "p r k and and not ,T T F";
    bool result = ev.eval(propo);
    bool result1 = ev.eval(propo1);
    cout << result << result1<<endl;
    return 0;
    }
