#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

 class rules {
 public:
 	rules(vector<string> rule1);
 	rules(){
 		
 	}
 	~rules(){

 	}
 	void addToSecondRule(vector<string> ruleN);
 	void addToFirstRule(vector<string> ruleN);
 	bool isInRule(string word, int rule);

 private:
 	list<vector<string>> rule;
 };

 rules::rules(vector<string> v){
 	rule.push_front(v);
 }

void rules::addToSecondRule(vector<string> ruleN){
	if(rule.size() == 1){
		rule.push_back(ruleN);
	}else {
		for (int i = 0; i < ruleN.size(); ++i){
			this->rule.back().push_back(ruleN[i]);
		}
	}
}

void rules::addToFirstRule(vector<string> ruleN){
	for (int i = 0; i < ruleN.size(); ++i){
			this->rule.front().push_back(ruleN[i]);
	}
}
 
bool rules::isInRule(string Word, int numbRule){
	if (numbRule == 0){
		for (auto i = rule.front().begin(); i != rule.front().end(); ++i){
			if (Word == *i){
				return true;
			}
		}
	}else{
		for (auto i = rule.back().begin(); i != rule.back().end(); ++i){
			if (Word == *i){
				return true;
			}
		}
	}
	return false;
}