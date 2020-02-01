#ifndef TC_PROYECTO_RULES_H
#define TC_PROYECTO_RULES_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

class rules {
private:
    list<vector<string>> rule;

public:
    rules(vector<string> rule1);

    rules();

    ~rules();

    void addToSecondRule(vector<string> ruleN);

    void addToFirstRule(vector<string> ruleN);

    bool isInRule(string Word, int numbRule);
};

#endif //TC_PROYECTO_RULES_H
