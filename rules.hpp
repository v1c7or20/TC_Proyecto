#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
 
 class rules {
 public:
 	rules(vector<int> rule1);
 	~rules();
 	bool isInVector(string word, int rule);

 private:
 	list<vector<int>> rule;
 };