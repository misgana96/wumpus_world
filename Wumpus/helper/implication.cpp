/** program_implication.cpp ---
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

#include <iostream>
#include <iomanip>
#include "implication.hpp"
#include "types.hpp"

using namespace Wumpus;
using namespace helper;


/**
 * @param A which is boolean either true or false
 * @param B which is boolean either true or false
 * @return true if it is true imp true, false imp true and false imp false else false
 */
bool Implication::implication(bool A,bool B)
{
    return not A or B;
}

/**
 * @param A which is bool either true or false
 * @return valuesOfNot
 */
valuesOfImp Implication::invOfImplication(bool A)
{
    if (A)
	{
		valuesOfImp result = {std::make_tuple(FALSE, TRUE)};
		return result;
	}
	else
	{
		valuesOfImp result = {std::make_tuple(TRUE, FALSE)};
		return result;
	}
}
