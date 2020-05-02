/** program_reverseL_parser.cpp ---
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
#include "reverseL_parser.hpp"
using namespace wumpus_world;
using namespace util;
using namespace helper;
using namespace std;

Negation rn;
L_and ra;
L_or ro;
implication rimp;
bi_implication rbimp;
bool rParser(vector<cell> propos, bool truthV,map<string,bool> &truthMap,stk<vectro<cell> reverse_iterator rit> &stkrit,stk<vectro<vector<cell>> iterator premit> &stkpremit,vectro<vector<cell>> iterator &premit){
stack<bool> stk;
stack<stack<bool>> stkStk;
stsStk.push(stk);

struct cellVisitor:public boost::static_visitor<statment>{

        public : statment operator()(statment statm)const{
                return statm;
                }
};

for (auto it = propos.rbegin();it != propos.rend();++it){


        if( *it == Lnot || *it == Land || *it == Lor || *it == Limp || *it == Lbimp ){
            if (*it == Lnot){
                (it == propos.rbegin()) ?bool tmp = rn.invOfNot(truthV) : bool tmp = rn.invOfNot(stkStk.top().top());
                stkStk.top().pop()
                stkStk.top().push(tmp);
                }
            else if(*it == Land){
                (it == propos.rbegin()) ? tuple<bool,int,bool> tup = ra.invOfAnd(truthV) : tuple<bool,int,bool> tup = ra.invOfAnd(stkStk.top().top());
                solveTuple(tup);
                }
            else if(*it == Lor){
                (it == propos.rbegin()) ? tuple<bool,int,bool> tup = ro.invOfOr(truthV) : tuple<bool,int,bool> tup = ro.invOfOr(stkStk.top().top());
                solveTuple(tup);
                }
            else if(*it == Limp){
               (it == propos.rbegin()) ? tuple<bool,int,bool> tup = ro.invOfImplication(truthV) : tuple<bool,int,bool> tup = ro.invOfImplication(stkStk.top().top());
                solveTuple(tup);
                }
            else if (*it == Lbimp){
               (it == propos.rbegin()) ? tuple<bool,int,bool> tup = ro.invOfBiImplication(truthV) : tuple<bool,int,bool> tup = ro.invOfBiImplication(stkStk.top().top());
                solveTuple(tup);
                    }
            }
        else{
            string Name = boost::apply_visitor(cellVisitor(),*it).getName;
            if(truthMap.find(Name)==truthMap.end()){
            truthMap.insert(Name,stkStk.top().top());
            stkStk.top().pop();
           }
           else{
               if(stkStk.top().top()== truthMap[Name]){
                  stkStk.top().pop();
                  continue;
                  }
                stkStk.pop();
                premit = stkpremit.top;
                return;
               }
        }


    }

void solveTuple(tuple<bool,int,bool> tup){

    bool branches = get<1>;
    bool tmp1 = get<0>tup;
    bool tmp2 = get<3>tup;
    if(branches) {
        stack<bool> stk1 = stkStk.top();
        stack<bool> stk1 = stkStk.top();
        stkStk.pop();
        stk1.push(tmp1);
        stk2.push(tmp2);
        stkStk.push(stk1);
        stkrit.push(it);
        stkpremit.push(premit);
        stkStk.push(stk2);
       }
    else{
        stkStk.top().push(tmp1);
        stkStk.top().push(tmp2);
       }

    }

