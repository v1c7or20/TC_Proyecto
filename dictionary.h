#ifndef TC_PROYECTO_DICTIONARY_H
#define TC_PROYECTO_DICTIONARY_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class dictionary {
private:
     vector<string>* words = nullptr;
public:
    dictionary();
    ~dictionary();
    bool isInDictionary(string wordToLook);
};

#endif //TC_PROYECTO_DICTIONARY_H
