#include <iostream>
#include <string>
#include <iterator>
#include "functions.cpp"

using namespace std;

int main(int argc, char const *argv[]){
	if(checkGrammar("einund")){
		cout<<"done"<<endl;
	}else{ 
		cout<<"dont done"<<endl;}
	return 0;
}