/** program_L_proposition.hpp ---
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
#ifndef L_PROPOSITION_HPP_INCLUDED
#define L_PROPOSITION_HPP_INCLUDED
#include "statment.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <boost/variant.hpp>

namespace Wumpus
{
namespace util
{

/*
*class L_proposition -- Defines logical statment;
*Given a string separated by a space, returns a vector of strings which form the logical proposition.
*proposition(W11 or B22 and B33) will return vector with elements W11, or, B22, and, B33 sequentialy.
*/
typedef boost::variant<statment,string> cell;
static cell Land = "and";
static cell Lor ="or";
static cell Lnot="not";
static cell Limp="imp";
static cell Lbimp="bimp";

class L_proposition
{

public :

    /*
    *func tokenize -- Tokenize A string to a vectror of substrings
    */

    vector<cell> proposition(string propos);
    vector<cell> propositiont(string propos,string tvalues);

    };

}
}
#endif // L_PROPOSITION_HPP_INCLUDED
