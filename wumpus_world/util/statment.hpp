/** program_statment.hpp ---
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


#ifndef STATMENT_HPP_INCLUDED
#define STATMENT_HPP_INCLUDED
#include <string>
namespace wumpus_world{
namespace util {
using namespace std;

class statment{

    private:
       string Statment;
       bool truthValue;
    public :

        statment(string statmt);
        void setTruthValue(bool TValue);
        bool getTruthValue();
        string getName();
        bool operator== (const statment& rhs) const;
        //friend ostream& operator<<(ostream& os,const statment& std);

    };
}
}
#endif // STATMENT_HPP_INCLUDED
