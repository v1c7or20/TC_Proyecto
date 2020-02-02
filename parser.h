#ifndef TC_PROYECTO_PARSER_H
#define TC_PROYECTO_PARSER_H

#include <string>
#include <vector>
#include <iostream>
#include "dictionary.h"

using namespace std;
class parser {
private:
    vector<string> *translatedWords= nullptr;
    dictionary *wordsToTranslate = nullptr;
public:
    parser();
    ~parser();
    string parse(string wordToTranslate);

};

#endif //TC_PROYECTO_PARSER_H
