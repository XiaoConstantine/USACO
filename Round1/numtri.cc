/*
	ID: constan10
	PROG: numtri
	LANG: C++11
*/


#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");

	int N;
	fin >> N;

	vector<vector<int> > data(N, vector<int>(N, 0));
	vector<vector<int> > dp(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++){
		for(int j = 0; j <= i; j++){
			fin >> data[i][j];
			if(i == N-1) dp[i][j] = data[i][j]; 
		}
	} 

	for(int i = N-2; i>= 0; i--){
		for(int j = 0; j <= i; j++){
			dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + data[i][j];
		}
	}
	fout << dp[0][0] << endl;
	return 0;
}