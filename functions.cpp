#include<string>
#include <iostream>

using namespace std;

string middleInterpretation(string word){
    string partialWord;
    string middle;
    for (auto letter = word.rbegin(); letter != word.rend() ; ++letter) {
        partialWord.insert(partialWord.begin(),*letter);
        if (partialWord == "father"){
            middle.insert(0,"fa()");
            partialWord = "";
        }else if(partialWord == "mother"){
            middle.insert(0,"mo()");
            partialWord = "";
        } else if(partialWord == "great" or partialWord == "grand"){
            middle.insert(0,"g(");
            middle.insert(middle.end(),')');
            partialWord = "";
        }
    }
    return middle;
}