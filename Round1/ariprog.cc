/*
	ID: constan10
	PROG: ariprog
	LANG: C++11
*/

#include <fstream>
#include <iostream>

using namespace std;

// 先试暴力的
int main(){
	/*
	ifstream fin("ariprog.in");
	ofstream fout("ariprog.out");
	int N, M;
	fin >> N >> M;

	int key, record;

	bool lis[125001] = {false}, flag, None = true;
	for(int p = 0; p <= M; p++){
		for(int q = 0; q <= M; q++){
			lis[p*p + q*q] = true;
		}
	}
	for(int b = 1; b <= 2*M*M/(N-1); b++){
		for(int a = 0; a + b*(N-1) <= 2*M*M; a++){
			for(int i = 0, record = 0; i < N; i++){
				key = a + i*b, flag = false;
				if(lis[key]){
					flag = true;
					record++;
				//	continue;
				}
				if(flag == false) break; 
			}
			if(record == N) {
				fout << a << " " << b << endl;
				None = false;
			}
		}
	}
	if(None == true) fout << "NONE" << endl;

*/
	ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");
    int N,M;
    fin>>N>>M;
    int a,b,p,q,key,i,record;
    bool flag, NONE=true, list[125001] = {false};
    for(p=0;p<=M;p++)
    {
        for(q=0;q<=M;q++)
        {
            list[p*p+q*q] = true;
        }
    }
    for(b=1;b<=2*M*M/(N-1);b++)
    {
        for(a=0;a+(N-1)*b<=2*M*M;a++)
        {
            for(i=0,record=0;i<N;i++)
            {
                key=a+i*b,flag=false;
                if(list[key]) {flag = true,record++;continue;}
                if(flag == false) break;
            }
            if(record == N) fout<<a<<" "<<b<<endl,NONE=false;
        }
    }
    if(NONE) fout<<"NONE"<<endl;
    fin.close(),fout.close();
    return 0;
	//return 0;
}