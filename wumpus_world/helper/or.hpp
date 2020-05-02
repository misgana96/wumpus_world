/** program_or.hpp ---
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
#ifndef HELPER_OR_HPP_INCLUDED
#define HELPER_OR_HPP_INCLUDED

#include <iostream>
#include <tuple>


using namespace std;
/*
*class and -- Implements logical or, and its invers functions
*Given two boolian truth values Or(true,False) will return true,Or(False,False) will return False,
Or(False,True) will return true, and Or(true,true) will return true
*for the inverse given a truth value invOfOr(true) will return T,T;T,F;F,T ...
*/
namespace wumpus_world
{
namespace helper
{

class L_or{

private:
    bool A,B,TValue;
public:
    bool Or(bool A,bool B); // Logical or
    tuple<bool, int , bool> invOfOr(bool TValue); // Inverse of Logical or Returns possible truth values.

    };
}
}

#endif // HELPER_OR_HPP_INCLUDED
