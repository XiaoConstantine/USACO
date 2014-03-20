/*
	ID: constan10
	PROG: ride
	LANG: C++11
*/

#include <fstream>
#include <string>
#include <iostream>
using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;


int main(){
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string comet, group;
	int comet_num = 1, group_num = 1;

	fin >> comet >> group;
	
	for(int i = 0; i < comet.length(); i++){
		comet_num *= comet[i] - 64;
	}
	for(int i = 0; i < group.length(); i++){
		group_num *= group[i] - 64;
	}
	comet_num %= 47;
	group_num %= 47;
	if(comet_num == group_num) fout << "GO" << endl;
	else fout << "STAY" << endl;

	return 0;
}

