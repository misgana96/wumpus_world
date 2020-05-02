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


bool bi_implication::Bi_Implication(bool A,bool B){
    if(A != true && A!= false && B != true && B!= false){
        return Bi_Implication(A,B);
        }
    else
        return A == B;
    }

tuple<bool, int , bool> bi_implication::invOfBiImplication(bool TValue){
    return (TValue == true ? make_tuple(true,0,false ) : make_tuple(true,1,false));
    }
