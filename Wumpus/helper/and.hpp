/** program_and.hpp ---
*
*
* Authors: Misgana <.com> and Elias Tsegaw<tsegawelias@gmail.com>
* Copyright (c) 2020 misgana96
* This program is free software; you can redistribute it and/or modify
* it under the terms of the  MIT License as
* published by the Free Software Foundation
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* MIT License for more details.
*
* You should have received a copy of the MIT License
* along with this program; if not, write to:
* Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef HELPER_AND_HPP_INCLUDED
#define HELPER_AND_HPP_INCLUDED


#include <iostream>
#include <tuple>

/*
*class and -- Implements logical and, and its invers functions
*Given two boolian truth values And(true,False) will return false,And(False,False) will return false,
And(False,True) will return false, and And(true,true) will return true
*for the inverse given a truth value invOfAnd(true) will return T,T ...
*/
namespace Wumpus
{
namespace helper
{
using namespace std;
class L_and{

private:
    bool A,B,TValue;

public:
    bool And(bool A,bool B); // Logical and
    tuple<bool, int , bool> invOfAnd(bool TValue); // Inverse of Logical and Returns possible truth values.

    };
}
}

#endif // HELPER_AND_HPP_INCLUDED
