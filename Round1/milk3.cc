/*
	ID: constan10
	PROG: milk3
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

long ans[50] = {0}, p = -1;
long a, b, c; // 桶容量上限
bool visit[21][21][21] = {false}; //记录是否DFS过这个分支

bool isIn(long C){
	bool ret = false;
	for(long i = 0; i <= p; i++){
		if(ans[i] == C){
			ret = true;
			break;
		}
	}
	return ret;
}

void DFS(long A, long B, long C){
	if(visit[A][B][C]) return;
	visit[A][B][C] = true;

	if(A == 0){
		if(!isIn(C)){
			ans[++p] = C;
		}
	}

	if(A <= b - B) DFS(0, B+A, C);   //A->B
	else DFS(A-(b-B), b, C);

	if(A <= c - C) DFS(0, B, C+A);   //A->C
	else DFS(A-(c-C), B, c);

	if(B <= a - A) DFS(A+B, 0, C);   //B->A
	else DFS(a, B-(a-A), C);

	if(B <= c - C) DFS(A, 0, C+B);   //B->C
	else DFS(A, B-(c-C), c);

	if(C <= a-A) DFS(A+C, B, 0);     //C->A
	else DFS(a, B, C-(a-A));

	if(C <= b-B) DFS(A, B+C, 0);	 //C->B
	else DFS(A, b, C-(b-B));

	return;


}

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");

	fin >> a >> b >> c;
	DFS(0, 0, c);

	sort(ans, ans+p+1);
	for(long i = 0; i <= p; i++){
		if(i != 0) fout << ' ';
		fout << ans[i];
	}
	fout << endl;
	return 0;


}
