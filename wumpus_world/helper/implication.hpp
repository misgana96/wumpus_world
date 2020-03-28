/** program_implication.hpp ---
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
#ifndef HELPER_IMPLICATION_HPP_INCLUDED
#define HELPER_IMPLICATION_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <tuple>
#include <array>

using namespace std;
/*
*class and -- Implements logical Implication, and its invers functions
*Given two boolian truth values Implication(False,true) will return true,and Implication(true,false) will return false
*for the inverse given a truth value invOfAnd(true) will return F,T ...
*/
namespace wumpus_world
{
namespace helper
{

struct values
{
	tuple<char, char>TruthValueOne;
	tuple<char, char>TruthValueTwo;
};
class implication{

private:
    bool A,B,TruthValue;
    char TruthValue;
public:
    bool Implication(bool A, bool B); // Logical Implication
    values invOfImplication(bool TruthValue); // Inverse of Logical Implication Returns possible truth values.

    };
}
}


#endif // HELPER_IMPLICATION_HPP_INCLUDED
