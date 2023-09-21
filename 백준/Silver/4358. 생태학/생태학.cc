#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#define pii pair<int,int>
#define endl '\n'
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
using namespace std;



void solution() {
	map<string, double> um;
	string s;
	double cnt = 0;
	while (getline(cin, s)) {
		um[s]++;
		cnt++;
	}
	for (auto it = um.begin(); it != um.end(); it++) {
		string temp = it->first;
		double d = round(it->second / cnt * 100 * 10000) / 10000;
		printf("%s %.4lf\n", temp.c_str(), d);
		//cout << it->first << " " << round(it->second / cnt * 100*10000)/10000 << endl;
	}
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(0);
	solution();
}