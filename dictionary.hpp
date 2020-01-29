#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>


using namespace std;


class dictionary{
 private:
 	vector<string> dict;
 public:
 	dictionary();
 	~dictionary();
 	bool find(string toLook);

 };

 dictionary::dictionary(){
 	dict.push_back("ein");
 	dict.push_back("zwei");
 	dict.push_back("drei");
 	dict.push_back("vier");
 	dict.push_back("fünf");
 	dict.push_back("sechs");
 	dict.push_back("sieben");
 	dict.push_back("acht");
 	dict.push_back("neun");
 	dict.push_back("zehn");
 	dict.push_back("elf");
 	dict.push_back("zwölf");
 	dict.push_back("sech");
 	dict.push_back("sieb");
 	dict.push_back("swan");
 	dict.push_back("hundert");
 	dict.push_back("tausend");
 	dict.push_back("zig");
 	dict.push_back("ssig");
 }

 bool dictionary::find(string toLook){
 	for(auto iter = dict.begin(); iter != dict.end(); iter++){
 		if (toLook == *iter){
 			return true;
 		}
 	}
 }