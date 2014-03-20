/*
	ID: constan10
	PROG: sprime
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
ifstream fin("sprime.in");
ofstream fout("sprime.out");


bool isPrime(long num)
{
     if (num==1 || num==0)
        return false;
     for (long i=2;i*i<=num;i++)
     {
         if (num%i==0)
            return false;
     }
     return true;
}

void DFS(long num, long times){
	if(times == 0){
		fout << num << endl;
		return;
	}
	times--;
	for(long i = 1; i <= 9; i++){
		if(isPrime(num*10 + i)){
			DFS(num*10+i, times);
		}
	}
	return;

}
int main(){
	
	long len;
	fin >> len;

	DFS(0, len);
	return 0;
}