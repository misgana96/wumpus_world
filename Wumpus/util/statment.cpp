/** program_statment.cpp ---
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
#include "statment.hpp"
using namespace Wumpus;
using namespace util;
    statment::statment(string statmt){
        Statment = statmt;
        }
    void statment::setTruthValue(bool TValue){
       truthValue = TValue;
        }
    bool statment::getTruthValue(){
        return truthValue;
        }
     string statment::getName(){
         return Statment;
         }

  bool statment::operator== (const statment& rhs) const
    {

        return (statment::Statment == rhs.Statment);
    }

   /* ostream& statment::operator<<(ostream& os,const statment& statm)
    {
        os <<statm.statment::Statment;
        return os;
        }
*/
