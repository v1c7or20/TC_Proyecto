#include<string>
#include <iostream>

using namespace std;

string middleInterpretation(string word){
    bool controlFoM = false, controlG = false;
    string partialWord;
    string middle;
    int errorIn = 0;
    for (auto letter = word.rbegin(); letter != word.rend() ; ++letter) {
        errorIn += 1;
        partialWord.insert(partialWord.begin(),*letter);
        if (partialWord == "father" and !controlFoM){
            middle.insert(0,"fa()");
            partialWord = "";
            controlFoM = true;
        }else if(partialWord == "mother" and !controlFoM){
            middle.insert(0,"mo()");
            partialWord = "";
            controlFoM = true;
        } else if(partialWord == "grand" and !controlG){
            middle.insert(0,"g(");
            middle.insert(middle.end(),')');
            partialWord = "";
            controlG = true;
        }else if(partialWord == "great" and controlG){
            middle.insert(0,"g(");
            middle.insert(middle.end(),')');
            partialWord = "";
        }else{
            if(partialWord.size() > 6 ){
                cout<<"Error en la frase: "<<partialWord<<"en el caracter numero "<<errorIn<<endl;
                return "error";
            }
        }
    }
    if(!partialWord.empty()){
        cout<<"Error en la frase: "<<partialWord<<endl;
        return "error";
    }
    return middle;
}

string finalInterpretation(string word){
    int count = 0;
    bool controlFoM = false, controlG = false;
    string partialWord;
    string middle;
    int errorIn=0;
    for (auto letter = word.rbegin(); letter != word.rend() ; ++letter) {
        partialWord.insert(partialWord.begin(), *letter);
        errorIn +=1;
        if (partialWord == ")") {
            count += 1;
            partialWord = "";
        }else if (partialWord == "fa(" and !controlFoM and count>0){
            middle.insert(0,"vatter");
            partialWord = "";
            count -=1;
            controlFoM = true;
        }else if(partialWord == "mo(" and !controlFoM and count>0){
            middle.insert(0,"mutter");
            partialWord = "";
            controlFoM = true;
            count -=1;
        } else if( partialWord == "g(" and controlFoM and !controlG and count>0){
            middle.insert(0,"gross");
            partialWord = "";
            controlG = true;
            count -=1;
        }else if (partialWord == "g(" and controlFoM and controlG and count>0){
            middle.insert(0,"ur");
            partialWord = "";
            count -=1;
        }else{
            if(partialWord.size() > 3 or count == 0){
                cout<<"Error en la frase: "<<partialWord<<"en el caracter numero "<<errorIn<<endl;
                return "error";
            }
        }
    }
    return middle;
}