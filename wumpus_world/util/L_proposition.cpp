/** program_L_proposition.cpp ---
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

#include "L_proposition.hpp"

 using namespace wumpus_world;
 using namespace util;
 using namespace std;
 typedef boost::variant<statment, string> cell;


     vector<cell> L_proposition::proposition(string propos){
         char delim = ' ';
         vector<cell> out;
         int start;
         int end =0;
         while((start = propos.find_first_not_of(delim,end)) != string::npos){
             end = propos.find(delim, start);
             string substr = propos.substr(start,end - start);
             cell tmpstr = substr;
             cell tmpStat(substr);
             if((tmpstr == Lnot) || (tmpstr == Land) || (tmpstr == Lor) || (tmpstr == Limp) || (tmpstr == Lbimp)) {
                  out.push_back(tmpstr);
             }
             else {
                 out.push_back(tmpStat);
             }

             }

         return out;
         }

     vector<cell> L_proposition::propositiont(string propos,string tValues){
        vector<cell> out = proposition(propos);

        struct cellVisitor:public boost::static_visitor<statment>{
            public : statment operator()(statment statm)const{
                return statm;}};

         int start;
         int end = 0;
         for (auto it = out.begin();it != out.end();++it){

         if (((*it == Lnot) || (*it == Land) || (*it == Lor) || (*it == Limp) || (*it == Lbimp) )) continue;

         if ((start = tValues.find_first_not_of(' ',end))!=string::npos){
             end = tValues.find(' ', start);
             string tmp = tValues.substr(start,end - start);
             if (tmp == "T"||tmp == "F") {
                 if(tmp =="T") {
                     statment st = boost::apply_visitor(cellVisitor(),*it);
                     st.statment::setTruthValue(true);
                     *it = st;
                     }
                 else{
                     statment st = boost::apply_visitor(cellVisitor(),*it);
                     st.statment::setTruthValue(false);
                     *it = st;
                 }
                 }
             else{
                 continue;
                 }

             }

         }
         return out;
        }




