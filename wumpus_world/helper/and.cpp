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

#include "and.hpp"
using namespace wumpus_world;
using namespace helper;

std::map<char, char> Truthmap =
{
	{'A', 'T'},
	{'B', 'F'}
};

bool and::And(bool A,bool B){
    if(A != true || A!= false || B != true || B!= false){
        return And(A,B);
        }
    else
        return A&&B;
    }
values and::invOfAnd(bool TruthValue){
    if (TruthValue == true)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['A'])};
		return result;
	}
	else if (TruthValue == false)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['B']), std::make_tuple(Truthmap['B'], Truthmap['A'])};
		return result;
	}
	else
	{
		return InvOfAnd(TruthValue);
	}
    }
