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
/*-----Translate the sentence-----*/
string parser::parse(string sentenceToTranslate) {
    string translatedSentence;
    string partialWord;
    bool theControl = false;
    bool nameControl = false;
    bool ofControl = false;
    bool control = false;   //controls the first "of"
    bool isFather = false;  //controls if the last word read is father, else is mother
    int count = 0;          //count the number of "father" or "mother" read
    int errorIn = 0;
    for (auto letter = sentenceToTranslate.rbegin();letter != sentenceToTranslate.rend(); letter++  ) {
        errorIn +=1;
        if(*letter != ' '){
            partialWord.insert(partialWord.begin(), *letter);
        }
        if (wordsToTranslate->isInDictionary(partialWord)){
            if ((partialWord == "Mary" or partialWord == "John") and !nameControl and !theControl){
                translatedSentence.insert(0, partialWord);
                partialWord = "";
                nameControl = true;
            } else if( partialWord == "of" and nameControl and  !ofControl ){
                if (!control and !theControl){
                    translatedSentence.insert(0,translatedWords->at(6)+" ");
                    partialWord = "";
                    control = true;
                    ofControl = true;
                    theControl = false;
                }else {
                    partialWord = "";
                    ofControl = true;
                    theControl = false;
                }
            } else if((partialWord == "father" or partialWord == "mother") and nameControl and ofControl){
                count +=1;
                isFather = partialWord == "father";
                partialWord = "";
                ofControl = false;
            } else if (partialWord == "the" and !theControl){
                partialWord = "";
                theControl = true;
            } else if(partialWord == "The"){
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
                partialWord ="";
            }else{
                if(partialWord.size() > 7){
                    cout<<"Error en la frase: "<<partialWord<<"en entre el caracter numero "<<errorIn<<" y "<<errorIn - 7<<endl;
                    return "error";
                }
            }
        }else{
            if(partialWord.size() > 7){
                cout<<"Error en la frase: "<<partialWord<<"en entre el caracter numero "<<errorIn<<" y "<<errorIn - 7<<endl;
                return "error";
            }
        }
    }
    if(!partialWord.empty()){
        cout<<"Error en la frase: "<<partialWord<<"en entre los ultimos 6 caracteres."<<endl;
        return "error";
    }
    return translatedSentence;
}
