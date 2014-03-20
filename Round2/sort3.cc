/*
	ID: constan10
	PROG: sort3
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");

	int N, val, ret = 0;
	fin >> N;
	vector<int> data;
	for(int i = 0; i < N; i++){
		fin >> val;
		data.push_back(val);
	}

	int one = 0, two = 0, three = data.size()-1;
	while(two <= three){
		if(data[two] == 2) two++;
		else if(data[two] == 1){
			swap(data[one++], data[two++]);
			ret++;
		}else{
			swap(data[two], data[three--]);
			ret++;
		}
	}
	fout << ret << endl;
	return 0;
}
