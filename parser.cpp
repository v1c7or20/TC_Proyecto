#include "parser.h"

parser::parser() {
    translatedWords = new vector<string>();
    translatedWords->push_back("gross");
    translatedWords->push_back("ur");
    translatedWords->push_back("vater");
    translatedWords->push_back("mutter");
    translatedWords->push_back("Die");
    translatedWords->push_back("Eine");
    translatedWords->push_back("von");
    translatedWords->push_back("John");
    translatedWords->push_back("Mary");
    wordsToTranslate = new dictionary();
}

parser::~parser() {
    delete(translatedWords);
    translatedWords = nullptr;
}

string parser::parse(string sentenceToTranslate) {
    string translatedSentence;
    string partialWord;
    bool control = false;
    bool isFather = false;
    int count = 0;
    for (auto letter = sentenceToTranslate.rbegin();letter != sentenceToTranslate.rend(); letter++  ) {
        if(*letter != ' '){
            partialWord.insert(partialWord.begin(), *letter);
        }
        if (wordsToTranslate->isInDictionary(partialWord)){
            if (partialWord == "Mary" or partialWord == "John"){
                translatedSentence.insert(0, translatedWords->at(8));
                partialWord = "";
            } else if( partialWord == "of"){
                if (!control){
                    translatedSentence.insert(0,translatedWords->at(6)+" ");
                    partialWord = "";
                    control = true;
                }else {
                    partialWord = "";
                }
            } else if(partialWord == "father" or partialWord == "mother"){
                count +=1;
                isFather = partialWord == "father";
                partialWord = "";
            } else if (partialWord == "the"){
                partialWord = "";
            } else {
                string grossurMaker;
                if (isFather){
                    grossurMaker.insert(0,"vater ");
                } else{
                    grossurMaker.insert(0,"mutter ");
                }
                for (int contador = 0; contador < count-1 ; ++contador) {
                    if(contador == 0){
                        grossurMaker.insert(0, "gross");
                    } else{
                        grossurMaker.insert(0,"ur");
                    }
                }
                translatedSentence.insert(0,grossurMaker);
                if(count==1){
                    translatedSentence.insert(0,"Die ");
                } else{
                    translatedSentence.insert(0,"Ein ");
                }
            }
        }
    }
    return translatedSentence;
}
