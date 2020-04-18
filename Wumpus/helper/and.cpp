/** program_and.cpp ---
*
*
* Authors: Misgana <misganayoseph@gmail.com> and Elias Tsegaw<tsegawelias@gmail.com>
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

#include <iostream>
#include <iomanip>
#include "and.hpp"
#include "types.hpp"


using namespace Wumpus;
using namespace helper;

And::And(){}

And::And(bool A, bool B)
{
    this->A = A;
    this->B = B;
}

bool And::getAnd(bool A,bool B)
{
    return A and B;
}

valuesOfAnd And::invOfAnd(bool A)
{
    if (A)
	{
		valuesOfAnd result = {make_tuple(TRUE, TRUE)};
		return result;
	}
	else
	{
		valuesOfAnd result = {make_tuple(TRUE, FALSE), make_tuple(FALSE, TRUE)};
		return result;
	}

}
