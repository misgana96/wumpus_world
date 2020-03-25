#include "../include/toPostfix.hpp"
#include "../include/proposition.hpp"


int precedence(TruthValue A){
    if(A == TruthValue::And){
        return 3;
        }
    else if(A == TruthValue::Or){
        return 2;
        }
    else if(A == TruthValue::Negation){
        return 4;
        }
    else if(A == TruthValue::Implication || A == TruthValue::BiImplication){
        return 1;
        }
    else{
        return 0;
        }
    }
    proposition toPostfix(proposition infix){

    proposition postfix;
    proposition::iterator it;

    for(it = infix.begin();it!= infix.end();it ++){
        if(typeid(*it) == typeid(proposition)){
            while(!tmp.empty()&&precedence(tmp.top())>=precedence(*it)){
                postfix.add();
                tmp.pop();
                }
                tmp.push(*it);

            }
          else if (*it == '('){
              tmp.push(*it)
              }
           else if (*it == ')'){
               while(tmp.top()!='('){
                   postfix.add();
                tmp.pop();
                }
                tmp.pop();
                   }
             else{
                 postfix.add();
                 }
               }
       while(!tmp.empty()){
           postfix.add();
           tmp.pop();
           }
        }

