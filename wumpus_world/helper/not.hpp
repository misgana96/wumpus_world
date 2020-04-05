/** program_not.hpp ---
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
#ifndef HELPER_NOT_HPP_INCLUDED
#define HELPER_NOT_HPP_INCLUDED

#include <iostream>
#include <iomanip>
#include <tuple>
#include <array>

using namespace std;
/*
*class not -- Implements logical negation and its invers functions
*Given a boolian truth value Not(true) will return false and vice versa
*for the inverse given a truth value invOfNot(true) will return F.
*/
namespace wumpus_world
{
namespace helper
{
class not{

private:
    bool A;
    char TruthValue;
public:
    bool Not(bool A); // Logical Not
    char invOfNot(bool A); // Inverse of Logical Not

    };
}
}
#endif // HELPER_NOT_HPP_INCLUDED
