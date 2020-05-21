#include "../../Wumpus/helper/and.hpp"
#include<iostream>
using namespace Wumpus::helper;
using namespace std;
int main(){
    L_and test;

    cout << test.And(true,true) << endl;
    cout << test.And(true,false) << endl;
    cout << test.And(false,true) << endl;
    cout << test.And(false,false) << endl;

    tuple<bool,int,bool> truth_values1 = test.invOfAnd(true);
    tuple<bool,int,bool> truth_values2 = test.invOfAnd(false);

    cout << get<0>(truth_values1) << endl;
    cout << get<1>(truth_values1) << endl;
    cout << get<2>(truth_values1) << endl;

    cout << get<0>(truth_values2) << endl;
    cout << get<1>(truth_values2) << endl;
    cout << get<2>(truth_values2) << endl;

return 0;
}
