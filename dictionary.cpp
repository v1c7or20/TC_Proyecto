#include "dictionary.h"

dictionary::dictionary() {
    words = new vector<string>();
    words->push_back("great");
    words->push_back("grand");
    words->push_back("father");
    words->push_back("mother");
    words->push_back("The");
    words->push_back("of");
    words->push_back("Mary");
    words->push_back("John");
    words->push_back("the");
}

dictionary::~dictionary() {
    delete(words);
    words = nullptr;
}

bool dictionary::isInDictionary(string wordToLook) {
    for (auto &i : *words){
        if (wordToLook == i){
            return true;
        }
    }
    return false;
}
