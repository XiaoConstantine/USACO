/*
	ID: constan10
	PROG: pprime
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <string.h>
#include <cstdio>

using namespace std;
ifstream fin("pprime.in");
ofstream fout("pprime.out");
long a, b;

bool isprime(long x){
	if(x%2==0) return 0;
	for (int i=3;i*i<=x;i+=2) if(x%i==0) return 0;
	return 1;
}

//构建回文数，将一个数翻转 然后连接。这里会出现中间的字符 repeat否的问题
//比如 123-》 123321 （重复） -》12321（不重复） 故有genoddeven

void gen(int i, int isodd){
	char buf[30];
	char *p, *q;
	long n;
	sprintf(buf, "%d", i);

	p = buf + strlen(buf);
	q = p - isodd;

	while(q > buf){
		*p++ = *--q;
	}
	*p = '\0';
	n = atol(buf);

	if(a <= n && n <= b && isprime(n)){
		fout << n << endl;
	}
}

void genoddeven(int lo, int hi){
	int i;
	for(i = lo; i <= hi; i++){
		gen(i, 1);
	}
	for(i = lo; i <= hi; i++){
		gen(i, 0);
	}
}

void generate(){
	genoddeven(1, 9);
	genoddeven(10, 99);
	genoddeven(100, 999);
	genoddeven(1000, 9999);
}

int main(){
	fin >> a >> b;
	generate();
	return 0;	

}