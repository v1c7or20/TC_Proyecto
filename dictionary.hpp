#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


class dictionary
 {
 public:
 	dictionary();
 	~dictionary();
 	bool find(string toLook):

 private:
 	std::vector<string> disct;
 };

 dictionary::dictionary(){
 	disct.push_back("ein");
 	disct.push_back("zwei");
 	disct.push_back("drei");
 	disct.push_back("vier");
 	disct.push_back("fünf");
 	disct.push_back("sechs");
 	disct.push_back("sieben");
 	disct.push_back("acht");
 	disct.push_back("neun");
 	disct.push_back("zehn");
 	disct.push_back("elf");
 	disct.push_back("zwölf");
 	disct.push_back("sech");
 	disct.push_back("sieb");
 	disct.push_back("swan");
 	disct.push_back("hundert");
 	disct.push_back("tausend");
 	disct.push_back("zig");
 	disct.push_back("ssig");
 }