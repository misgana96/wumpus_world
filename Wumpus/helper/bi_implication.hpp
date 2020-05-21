/** program_bi_implication.hpp ---
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
#ifndef HELPER_BI_IMPLICATION_HPP_INCLUDED
#define HELPER_BI_IMPLICATION_HPP_INCLUDED


#include <iostream>
#include <iomanip>
#include <tuple>


using namespace std;
/*
*class and -- Implements logical Bi_Implication, and its invers functions
*Given two boolian truth values Bi_Implication(False,False)/(true,true) will return true,
and Implication(true,false)/(false,Ture) will return false
*for the inverse given a truth value invOfAnd(true) will return F,F;T,T ...
*/
namespace Wumpus
{
namespace helper
{

struct values
{
	tuple<char, char>TruthValueOne;
	tuple<char, char>TruthValueTwo;
};
class bi_implication{

private:
    bool A,B,TValue;

public:
    bool Bi_Implication(bool A, bool B); // Logical Bi_Implication
    tuple<bool, int , bool> invOfBiImplication(bool TValue); // Inverse of Logical Bi_Implication Returns possible truth values.

    };
}
}


#endif // HELPER_BI_IMPLICATION_HPP_INCLUDED
