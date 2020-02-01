//
// Created by asus on 2020-02-01.
//

#include "dictionary.h"

dictionary::dictionary() {
    dict.emplace_back("ein");dict.emplace_back("zwei");dict.emplace_back("drei");
    dict.emplace_back("vier");dict.emplace_back("fünf");dict.emplace_back("sechs");
    dict.emplace_back("sieben");dict.emplace_back("acht");dict.emplace_back("neun");
    dict.emplace_back("zehn");dict.emplace_back("elf");dict.emplace_back("zwölf");
    dict.emplace_back("sieb");dict.emplace_back("swan");dict.emplace_back("hundert");
    dict.emplace_back("tausend");dict.emplace_back("zig");dict.emplace_back("ssig");
    dict.emplace_back("sech");
}

bool dictionary::find(string toLook) {
    for(auto iter = dict.begin(); iter != dict.end(); iter++){
        if (toLook == *iter){
            return true;
        }
    }
    return false;
}

dictionary::~dictionary() {

}
