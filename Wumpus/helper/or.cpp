/** program_or.cpp ---
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

#include "or.hpp"
using namespace Wumpus;
using namespace helper;

bool L_or::Or(bool A,bool B){
    if(A != true && A!= false && B != true && B!= false){
        return Or(A,B);
        }
    else
        return A||B;
    }

tuple<bool, int , bool> L_or::invOfOr(bool TValue){
    return (TValue == true ? make_tuple(true,0,true ) : make_tuple(false,1,false));

    }

