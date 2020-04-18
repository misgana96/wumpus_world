/** program_or.cpp ---
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
#include <tuple>
#include "or.hpp"
#include "types.hpp"


using namespace Wumpus;
using namespace helper;


// /**
//  * definition of default and parameterize constructor
//  */
Or::Or(){};

Or::Or(bool A, bool B)
{
    this->A = A;
    this->B = B;
}

/**
 * @param A truth value which is eitherr true or false
 * @param B truth value which is either true or false
 * @return true is A or B is true else false
 */
bool Or::getOr(bool A,bool B)
{
    return A or B;
}

/** 
 * @param A which is either true or false
 * @return {true, falde} or {false, true} if invofOr is true else {false, false}
 */
valuesOfOr Or::invOfOr(bool A)
{
    if (A)
	{
		valuesOfOr result = {make_tuple(TRUE, FALSE), make_tuple(FALSE, TRUE)};
		return result;
	}
	else
	{
		valuesOfOr result = {make_tuple(FALSE, FALSE)};
		return result;
	}

}
