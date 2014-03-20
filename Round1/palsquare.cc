/*
	ID: constan10
	PROG: palsquare
	LANG: C++11
*/


#include <fstream>
#include <iostream>
#include <string>
using namespace std;

const char NUMBER[20] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                   'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

const int N = 300;
string convert(int a, int b){
	string ret;
	while(a){
		ret.insert(ret.begin(), NUMBER[a%b]);
		a /= b;
	}
	return ret;
}

bool isPalindrome(string str){
	for(auto start = str.begin(), end = str.end()-1; start < end; start++, end--){
		if(*start != *end) return false;
	}
	return true;
}

int main(){
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");
	int base;
	fin >> base;
	for(int i = 1; i <= N; i++){
		string ret = convert(i, base);
		string square = convert(i*i, base);
		if(isPalindrome(square)){
			fout << ret << " " << square << endl;
		}
	}
	return 0;
}