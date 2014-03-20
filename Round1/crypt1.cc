/*
	ID: constan10
	PROG: crypt1
	LANG: C++11
*/


#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int num_digits, num, count = 0;
	int arr[10];
	vector<bool> exist(10, false);

	fin >> num_digits;
	
	for(int i = 0; i < num_digits; i++){
		fin >> num;
		arr[i] = num;
		exist[arr[i]] = true;
	}
	/*
		* * *  a 表示这个数
	x	  * *
	----------
		* * *  b 表示这个
	  * * *    c 表示这个
	----------
	  *	* * *  d 表示这个

	 5 层 循环表示 5个digit 然后判断每一位 是不是存在
	*/

	for(int i = 0; i < num_digits; i++){
		for(int j = 0; j < num_digits; j++){
			for(int k = 0; k < num_digits; k++){
				
				for(int m = 0; m < num_digits; m++){
					for(int n = 0; n < num_digits; n++){
						
						int a = arr[i]*100 + arr[j]*10 + arr[k];
						int b = a*arr[m], c = a*arr[n], d = b+c*10;
						
						if(b > 1000 || c > 1000 || d > 10000) continue;
						if(exist[b%10] == 0 || exist[c%10] == 0 || !exist[d%10]) continue;
						b /= 10, c /= 10, d /= 10;

						if(!exist[b%10] || !exist[c%10] || !exist[d%10]) continue;
						d /= 10;
						if(!exist[b/10] || !exist[c/10] || !exist[d%10] || !exist[d/10]) continue;
						count++;
					}
				}
			}
		}
	}
	fout << count << endl;
	return 0;
}