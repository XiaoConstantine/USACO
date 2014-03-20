/*
	ID: constan10
	PROG: milk
	LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval
{
	int price, amount;
	bool operator<(const Interval& that) const{
		return price < that.price;
	}
	/* data */
};


int main(){
	ifstream fin("milk.in");
	ofstream fout("milk.out");

	int total_amount, N;
	int price, amount;

	fin >> total_amount >> N;
	if(total_amount == 0 || N == 0){
		fout << 0 << endl;
	}else{
		vector<Interval> farmers;
		for(int i = 0; i < N; i++){
			fin >> price >> amount;
			farmers.emplace_back(Interval{price, amount});
		}
		sort(farmers.begin(), farmers.end());
		int count_amount = 0, min_price = 0;
		for(int i = 0; i < farmers.size(); i++){
			if(count_amount + farmers[i].amount < total_amount){
				count_amount += farmers[i].amount;
				min_price += farmers[i].price*farmers[i].amount;
			}else{
				min_price += farmers[i].price*(total_amount - count_amount);
				fout << min_price << endl;
				break;
		}
		}
	}
	
	return 0;
}