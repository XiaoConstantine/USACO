/*
	ID: constan10
	PROG: barn1
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ifstream fin("barn1.in");
	ofstream fout("barn1.out");

	int max_boards, total_stalls, total_cows;
	fin >> max_boards >> total_stalls >> total_cows;

	int cow_num;
	vector<int> cows(total_stalls+1, 0);
	while(fin>>cow_num){
		cows[cow_num] = 1;
	}
	int begin, end;
	// find start pos where cow live and end pos
	for(auto it = cows.begin(); it != cows.end(); it++){
		if(*it){
			begin = it - cows.begin();
			break;
		}
	}
	for(auto it = cows.end()-1; it != cows.begin(); it--){
		if(*it){
			end = it - cows.begin();
			break;
		}
	}

	vector<int> blank;
	int is_blank = 0, blank_len = 0;
	for(int i = begin; i <= end; i++){
		if(cows[i]){
			if(is_blank){
				if(blank_len){
					blank.push_back(blank_len);
				}
				is_blank = 0;
				blank_len = 0;
			}
		}else{
			if(is_blank) blank_len++;
			else{
				is_blank = 1;
				blank_len = 1;
			}
		}
	}

	int len = end - begin + 1, boards = 1;
	if(blank.empty()){
		fout << len << endl;
	}else{
		sort(blank.begin(), blank.end());
		auto it = blank.rbegin();
		while(boards < max_boards && it != blank.rend()){
			len -= *it++;
			++boards;
		}
		fout << len << endl;
	}
	return 0;

}