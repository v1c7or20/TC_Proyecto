#include <vector>
#include <string>
#include "dictionary.h"
#include "rules.h"

using namespace std;

vector<rules> makeGrammarRules(){
    vector<string> Z1 {"ein","zwein","drei","vier","fünf","sechs","sieben","acht","neun"};
    vector<string> Z2 {"zehn","elf","zwölf"};
    vector<string> Z3 {"drei","vier","fünf","sech","sieb","acht","neun"};
    vector<string> Z4 {"zwan","vier","fünf","sech","sieb","acht","neun"};
    vector<string> Z5 {"hundert"};vector<string> Z6 {"tausend"};
    vector<string> drei {"drei"}; vector<string> zenh {"zehn"} ;
    vector<string> zig {"zig"}; vector<string> ssig {"ssig"};
    vector<string> und {"und"};

    rules R1(zenh), R2(zig), R3(ssig), R4(zig), R5(Z5),
            R6(Z5), R7(Z1), R8(Z1), R9(Z6), R10(Z1), R11(und);

    /*-----------------Make the second part of Rules-------------------*/
    R1.addToSecondRule(Z3);R2.addToSecondRule(Z4);R3.addToSecondRule(drei);
    R4.addToSecondRule(Z1);R4.addToSecondRule(und);R5.addToSecondRule(Z1);
    R6.addToSecondRule(Z2);R7.addToSecondRule(Z5);
    R8.addToSecondRule(Z2);R8.addToSecondRule(Z5);R9.addToSecondRule(Z1);
    R9.addToSecondRule(Z2);R9.addToSecondRule(Z4);R9.addToSecondRule(zig);
    R9.addToSecondRule(drei);R9.addToSecondRule(ssig);R9.addToSecondRule(und);
    R10.addToSecondRule(Z1);R10.addToSecondRule(Z2);R10.addToSecondRule(Z4);
    R10.addToSecondRule(zig);R10.addToSecondRule(drei);R10.addToSecondRule(ssig);
    R10.addToSecondRule(und);R10.addToSecondRule(Z6);R11.addToSecondRule(Z1);
    /*-----------------Make the first part of Rules-------------------*/
    R7.addToFirstRule(Z2);R7.addToFirstRule(Z4);R7.addToFirstRule(zig);
    R7.addToFirstRule(ssig);R7.addToFirstRule(drei);R7.addToFirstRule(und);
    R8.addToFirstRule(Z2);R8.addToFirstRule(Z4);R8.addToFirstRule(zig);
    R8.addToFirstRule(ssig);R8.addToFirstRule(drei);R8.addToFirstRule(und);
    R10.addToFirstRule(Z2);R10.addToFirstRule(Z4);R10.addToFirstRule(zig);
    R10.addToFirstRule(drei);R8.addToFirstRule(ssig);R8.addToFirstRule(und);
    R8.addToFirstRule(Z5);

    vector<rules> grammarRules {R1,R2,R3,R4,R5,R6,R7,R8,R9,R10,R11};
    return grammarRules;
}

bool checkGrammars(string word){
    vector<rules> grammarRules = makeGrammarRules();
    dictionary *Dictionary = new dictionary();
    string partWord = "";
    vector<rules> *ruleUsed = new vector<rules>();
    for (auto iter = word.rbegin(); iter != word.rend(); ++iter){
        if(partWord.size() > 8){
            return false;
        }else{
            partWord += *iter;
            if(Dictionary->find(partWord) && ruleUsed->size() == 0){
                for (auto ruleIterador = grammarRules.begin(); ruleIterador != grammarRules.end(); ++ruleIterador){
                    if((*ruleIterador).isInRule(partWord, 0)){
                        ruleUsed->push_back(*ruleIterador);
                    }
                }

            }
        }
    }
}


