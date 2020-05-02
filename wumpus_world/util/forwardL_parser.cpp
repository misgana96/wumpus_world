/** program_forwardL_parser.cpp ---
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
#include "forwardL_parser.hpp"
using namespace wumpus_world;
using namespace util;
using namespace helper;
using namespace std;
Negation n;
L_and a;
L_or o;
implication imp;
bi_implication bimp;
bool forwardL_parser::fParser(vector<cell> propos){
    stack<bool> stk;
    struct cellVisitor:public boost::static_visitor<statment>{

        public : statment operator()(statment statm)const{
                return statm;
                }
};

    for (auto it = propos.begin();it != propos.end();++it){

        if(*it == Lnot || *it == Land || *it == Lor || *it == Limp || *it == Lbimp) {
         if (*it == Lnot){
                //Negation n;
                //statment result("result");
                bool tmp = n.Not(stk.top());
                stk.pop();
                //result.setTruthValue(tmp);
                stk.push(tmp);
                }
            else if(*it == Land){
                //L_and a;
                //statment result("result");
                bool tmp1 = stk.top();
                stk.pop();
                bool tmp2 = stk.top();
                stk.pop();
                bool tmp3 = a.L_and::And(tmp1,tmp2);
                //result.setTruthValue(tmp3);
                stk.push(tmp3);
                }
            else if(*it == Lor){
                //L_or o;
                //statment result("result");
                bool tmp1 = stk.top();
                stk.pop();
                bool tmp2 = stk.top();
                stk.pop();
                bool tmp3 = o.L_or::Or(tmp1,tmp2);
                //result.setTruthValue(tmp3);
                stk.push(tmp3);
                }
            else if(*it == Limp){
                //implication imp;
                //statment result("result");
                bool tmp1 = stk.top();
                stk.pop();
                bool tmp2 = stk.top();
                stk.pop();
                bool tmp3 = imp.Implication(tmp1,tmp2);
                //result.setTruthValue(tmp3);
                stk.push(tmp3);
                }
            else if (*it == Lbimp){
                //bi_implication bimp;
               // statment result("result");
                bool tmp1 = stk.top();
                stk.pop();
                bool tmp2 = stk.top();
                stk.pop();
                bool tmp3 = bimp.Bi_Implication(tmp1,tmp2);
                //result.setTruthValue(tmp3);
                stk.push(tmp3);
                }

        }

            else {
            stk.push(boost::apply_visitor(cellVisitor(),*it).getTruthValue());
        }


        }


return stk.top();
    }
