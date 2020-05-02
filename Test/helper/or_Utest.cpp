#include "../../wumpus_world/helper/or.hpp"
using namespace wumpus_world::helper;
using namespace std;
int main(){

    L_or test;

    cout << test.Or(true,true) << endl;
    cout << test.Or(true,false) << endl;
    cout << test.Or(false,true) << endl;
    cout << test.Or(false,false) << endl;

    tuple<bool,int,bool> truth_values1 = test.invOfOr(true);
    tuple<bool,int,bool> truth_values2 = test.invOfOr(false);

    cout << get<0>(truth_values1) << endl;
    cout << get<1>(truth_values1) << endl;
    cout << get<2>(truth_values1) << endl;

    cout << get<0>(truth_values2) << endl;
    cout << get<1>(truth_values2) << endl;
    cout << get<2>(truth_values2) << endl;
return 0;
}
