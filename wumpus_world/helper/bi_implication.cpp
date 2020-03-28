/** program_bi_implication.cpp ---
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

#include "bi_implication.hpp"
using namespace wumpus_world;
using namespace helper;

std::map<char, char> Truthmap =
{
	{'A', 'T'},
	{'B', 'F'}
};

bool bi_implication::Bi_Implication(bool A,bool B){
    if(A != true || A!= false || B != true || B!= false){
        return Bi_Implication(A,B);
        }
    else
        return A == B;
    }
values bi_implication::invOfBi_Implication(bool TruthValue){
    if (TruthValue == true)
	{
		values result = {std::make_tuple(Truthmap['B'], Truthmap['A'])};
		return result;
	}
	else if (TruthValue == false)
	{
		values result = {std::make_tuple(Truthmap['A'], Truthmap['B'])};
		return result;
	}
	else
	{
		return InvOfBi_Implication(TruthValue);
	}
}
