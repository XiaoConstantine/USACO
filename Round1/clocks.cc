/*
	ID: constan10
	PROG: clocks
	LANG: C++11
*/

#include <fstream>
#include <iostream>

using namespace std;

int clocks[10], a[10], result[10], times[10];

void check(){
	for(int i=1; i < 10; i++){
		if(clocks[i] > 12) clocks[i] -= 12;
	}
}

// 暴力枚举
void spin(int a){
	if(a == 1){
		clocks[1] += 3;
		clocks[2] += 3;
		clocks[4] += 3;
		clocks[5] += 3;
		check();
		return;
	}
	if(a == 2){
		clocks[1] += 3;
		clocks[2] += 3;
		clocks[3] += 3;
		check();
		return;
	}
	if(a == 3){
		clocks[2] += 3;
		clocks[3] += 3;
		clocks[5] += 3;
		clocks[6] += 3;
		check();
		return;
	}
	if(a == 4){
		clocks[1] += 3;
		clocks[4] += 3;
		clocks[7] += 3;
		check();
		return;
	}
	if(a == 5){
		clocks[2] += 3;
		clocks[4] += 3;
		clocks[5] += 3;
		clocks[6] += 3;
		clocks[8] += 3;
		check();
		return;
	}
	if(a == 6){
		clocks[3] += 3;
		clocks[6] += 3;
		clocks[9] += 3;
		check();
		return;
	}
	if(a == 7){
		clocks[4] += 3;
		clocks[5] += 3;
		clocks[7] += 3;
		clocks[8] += 3;
		check();
		return;
	}
	if(a == 8){
		clocks[7] += 3;
		clocks[8] += 3;
		clocks[9] += 3;
		check();
		return;
	}
	if(a == 9){
		clocks[5] += 3;
		clocks[6] += 3;
		clocks[8] += 3;
		clocks[9] += 3;
		check();
		return;
	}
	else return;

}


int main(){
	ifstream fin("clocks.in");
	ofstream fout("clocks.out");
	int i, j, k, m = 0, n = 9999, x = 0, y = 0;
	bool judge = true;
	for(int i = 1; i <= 9; i++){
		fin >> clocks[i];
		times[i] = clocks[i];
	}

	for(a[1]=0;a[1]<=3;a[1]++)
	{
		for(a[2]=0;a[2]<=3;a[2]++)
		{
			for(a[3]=0;a[3]<=3;a[3]++)
			{
				for(a[4]=0;a[4]<=3;a[4]++)
				{
					for(a[5]=0;a[5]<=3;a[5]++)
					{
						for(a[6]=0;a[6]<=3;a[6]++)
						{
							for(a[7]=0;a[7]<=3;a[7]++)
							{
								for(a[8]=0;a[8]<=3;a[8]++)
								{
									for(a[9]=0;a[9]<=3;a[9]++)
									{
										for(i=1;i<10;i++)
											clocks[i]=times[i];
										for(i=1;i<=9;i++)
											for(j=0;j<a[i];j++)
												spin(i);
										for(i=1;i<10;i++)
								 		{
											if(clocks[i]!=12)
												judge=false;
										}
										if(judge)
											if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]<n)
											{
												for(i=1;i<10;i++)
													result[i]=a[i];
												n=a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9];
											}
										judge=true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	int flag = 0;
	for(i = 1; i < 10; i++){
		for(j=1; j <=result[i]; j++){
			if(flag) fout << " ";
			else{
				flag = true;
			}
			fout << i;
		}
	}
	fout << endl;
	return 0;
}