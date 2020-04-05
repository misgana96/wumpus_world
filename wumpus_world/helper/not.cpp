/** program_not.cpp ---
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

#include "not.hpp"
using namespace wumpus_world;
using namespace helper;

bool not::Not(bool A){
    if(A != true || A!= false){
        return Not(A);
        }
    else
        return !A;
    }
char not::invOfNot(bool A){
    if (A == false)
	{
		TruthValue = 'T';
	}
	else if (A == true)
	{
		TruthValue = 'F';
	}
	else
	{
		return A;
	}
    return TruthValue;
    }
