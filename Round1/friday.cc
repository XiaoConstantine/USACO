/*
	ID: constan10
	PROG: friday
	LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int dayOfMonth[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int ret[7] = {0};
	int n, last = 3;
	fin >> n;
	for(int i = 1900; i < 1900+n; i++){
		if(i%400 == 0 || (i%100 != 0 && i % 4 == 0)) dayOfMonth[2] = 29;
		for(int j = 0; j < 12; j++){
			last = (last + dayOfMonth[j])%7;
			ret[last]++;
		}
		dayOfMonth[2] = 28;
	} 
	for(int i = 0; i < 6; i++){
		fout << ret[(i+6)%7] << ' ';
	}
	fout << ret[5] << endl;
	return 0;
}