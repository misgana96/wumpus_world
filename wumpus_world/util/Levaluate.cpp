/** program_Levaluate.cpp ---
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
#include "Levaluate.hpp"
using namespace wumpus_world;
using namespace util;
using namespace std;
bool Levaluate::eval(string proposit){
    int pos = proposit.find_first_of(',');
    string propos = proposit.substr(0,pos);
    string tvalues = proposit.substr(pos + 1);
    L_proposition p;
    forwardL_parser f;
    vector<cell> prop = p.L_proposition::propositiont(propos,tvalues);
    bool parsed = f.fParser(prop);
    return parsed;
    }
