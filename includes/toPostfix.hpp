#ifndef TOPOSTFIX_H_INCLUDED
#define TOPOSTFIX_H_INCLUDED

#include <iostream>
#include <stack>
#include "helper.hpp"
#include "proposition.hpp"
using namespace TruthValues
using std::stack
private:
    stack<TruthValues> tmp;
public:
    int precedence(TruthValue A);
    proposition toPostfix(proposition infix);
#endif // TOPOSTFIX_H_INCLUDED
