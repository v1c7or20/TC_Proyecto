#include <iostream>
#include "function.cpp"

using namespace std;

int main(int argc, char const *argv[]){
    if(checkGrammars("einund")){
        cout<<"Done"<<endl;
    }else{
        cout<<"Dont done"<<endl;
    }
	return 0;
}