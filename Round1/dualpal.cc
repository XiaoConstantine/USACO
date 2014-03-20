/*
	ID: constan10
	PROG: dualpal
	LANG: C++11
*/


#include <fstream>
#include <iostream>

using namespace std;

bool check(int num){
	int times = 0;
	for(int i = 2; i <= 10; i++){
		int p = 0, que[32], x = num;
		while(x){
			que[p++] = x%i;
			x /= i;
		}
		bool ok = 1;
		for(int j = 0; ok &&(j <= p-1); j++) ok = (ok && que[j] == que[p-j-1]);
		if(ok) times++;
		if(times > 1) return true;
	}
	return false;
}

int main(){
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");
	int N, S;
	fin >> N >> S;
	for(int i = S+1; N; i++){
		if(check(i)){
			fout << i << endl;
			N--;
		}
	}

	return 0;
}