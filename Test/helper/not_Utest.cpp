#include "not.hpp"
using namespace std;
using namespace Wumpus::helper;
int main(){
    Negation test;

    cout << test.Not(true) << endl;
    cout << test.Not(false) <<endl;
    cout << test.invOfNot(true)<<  endl;
    cout << test.invOfNot(false)<< endl;
return 0;
}
