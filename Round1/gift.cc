/*
	ID: constan10
	PROG: gift1
	LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ofstream;
using std::ifstream;
using std::endl;

int main(){
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");
	static int ans[10];
	int np,i,j,p,ini,ng;
	string a[10],giv,rec;
	fin>>np;
	for (i=0;i<np;i++)
		fin>>a[i];
	for (i=0;i<np;i++)
	{
		fin>>giv>>ini>>ng;
		for (p=0;giv!=a[p];p++);
		ans[p]-=ng==0?0:ini-ini%ng;
		for (j=0;j<ng;j++)
		{
			fin>>rec;
			for (p=0;rec!=a[p];p++);
			ans[p]+=ini/ng;
		}
	}
	for (i=0;i<np;i++)
		fout<<a[i]<<' '<<ans[i]<<endl;
	return 0;
}