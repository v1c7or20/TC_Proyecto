#include <iostream>
#include <string>
#include <iterator>
#include "functions.cpp"

using namespace std;

dictionary dict();
vector<string> Z1 {"ein","zwein","drei","vier","fünf","sechs","sieben","acht","neun"};
vector<string> Z2 {"zehn","elf","zwölf"};
vector<string> Z3 {"drei","vier","fünf","sech","sieb","acht","neun"};
vector<string> Z4 {"zwan","vier","fünf","sech","sieb","acht","neun"};
vector<string> Z5 {"hundert"};
vector<string> Z6 {"tausend"};
vector<string> drei {"drei"};
vector<string> zenh {"zehn"} ;
vector<string> zig {"zig"} ;
vector<string> ssig {"ssig"};
vector<string> und {"und"};

rules R1(zenh), R2(zig), R3(ssig), R4(zig), R5(Z5),
 R6(Z5), R7(Z1), R8(Z1), R9(Z6), R10(Z1), R11(und);

int main(int argc, char const *argv[]){
	
	return 0;
}