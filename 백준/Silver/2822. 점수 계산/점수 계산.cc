#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
using namespace std;



void solution() {
	vector<pii> v(8);
	for (int i = 0; i < 8; i++) {
		int temp;
		cin >> temp;
		v[i] = { temp, i+1 };
	}
	sort(v.begin(), v.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		ans += v[i].first;
	}
	vector<int> vv(5);
	for (int i = 0; i < 5; i++) {
		vv[i] = v[i].second;
	}
	sort(vv.begin(), vv.end());
	cout << ans << endl;
	for (auto a : vv) {
		cout << a << " ";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solution();
}