/*
	ID: constan10
	PROG: beads
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <string>
#include <limits>
using namespace std;

int main(){
	ifstream fin("beads.in");
	ofstream fout("beads.out");
	string input;
	int size;
	fin >> size;
	fin >> input;
	char s1, s2;
	int max_len = 0, j, k;
	for(int i = size; i < size*2; i++){
		if(input[i%size] != input[(i+1)%size]){
			s1 = input[i%size] != 'w'?input[i%size]:(input[(i+1)%size] == 'r'?'b':'r');
			s2 = s1=='r'?'b':'r';
			int len = 0;
			for(j = i; j > i - size; j--){
				if(input[j%size] == s1 || input[j%size] == 'w')len++;
				else break;
			}
			for(k = i+1; k < j+size+1; k++){
				if(input[k%size] == s2 || input[k%size] == 'w') len++;
				else break;
			}
			max_len = max(max_len, len);
		}
	}
	if(max_len == 0) max_len = size;
		
	fout << max_len << endl;
	return 0;
}