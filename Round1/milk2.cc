/*
	ID: constan10
	PROG: milk2
	LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;
struct Interval
{
	int start, end;
	bool operator<(const Interval &that) const{
		return start != that.start?start<that.start:end < that.end;
	}
	/* data */
};

int main(){
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");
	vector<Interval> ret;
	int n, start, end;
	fin >> n;

	for(int i = 0; i < n; i++){
		fin >> start >> end;
		ret.emplace_back(Interval{start, end});
	}
	sort(ret.begin(), ret.end());

	Interval cur = ret[0];
	int max_get = 0, max_none = 0, t;
	for(int i = 1; i < ret.size(); i++){
		if(ret[i].start > cur.end){
			t = ret[i].start - cur.end;
			if(t > max_none) max_none = t;

			t = cur.end - cur.start;
			if(t > max_get) max_get = t;
			cur = ret[i];
		}else{
			if(ret[i].end > cur.end) cur.end = ret[i].end;
		}
	}
	t = cur.end - cur.start;
	if(t > max_get) max_get = t;
	fout << max_get << " " << max_none << endl;
	return 0;




}

