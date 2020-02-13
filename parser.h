#ifndef TC_PROYECTO_PARSER_H
#define TC_PROYECTO_PARSER_H

#include "dictionary.cpp"
using namespace std;
/*----------class in charge of the translation--------*/
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
