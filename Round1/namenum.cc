/*
	ID: constan10
	PROG: namenum
	LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const char alpha[26] = {'2','2','2','3','3','3','4','4','4','5','5','5', '6','6','6','7','0','7','7','8','8','8','9','9','9','0'};
string words, data, tmp;
bool hasRet = false;
int main(){
	ifstream fin("namenum.in");
	ofstream fout("namenum.out");
	ifstream tin("dict.txt");
	
	fin >> data;

	while(tin >> words){
		tmp = "";
		for(int i = 0; i < words.size();i++){
			tmp += alpha[words[i] - 65];
		}
		if(tmp == data) {
			fout << words << endl;
			hasRet = true;
		}
	}
	if(!hasRet) fout << "NONE" << endl;
	return 0;
}
