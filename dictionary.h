#ifndef TC_PROYECTO_DICTIONARY_H
#define TC_PROYECTO_DICTIONARY_H

#include <string>
#include <iostream>
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

#endif //TC_PROYECTO_DICTIONARY_H
