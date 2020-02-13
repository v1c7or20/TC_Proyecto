#include <iostream>
#include "parser.h"
#include "functions.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    parser *Parser = new parser();
    string toTranslate("The father of the mother of the mother of the mother of the father of John");
    cout<<Parser->parse(toTranslate)<<endl;
    cout<<middleInterpretation("greatgreatgreatgrandmother")<<endl;
    cout<<middleInterpretation("grandgreatgreatgrandmother")<<endl;
    cout<<finalInterpretation(middleInterpretation("greatgreatgreatgrandmother"))<<endl;
    cout<<finalInterpretation("g(g(fa(g(mo()))))")<<endl;

    return 0;
}