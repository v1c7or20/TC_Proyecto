#include <iostream>
#include "parser.h"
#include "dictionary.h"

using namespace std;

int main(int argc, char const *argv[]){
    parser *Parser = new parser();
    string toTranslate("The father of the mother of the mother of the father of John");
    cout<<Parser->parse(toTranslate);
	return 0;
}