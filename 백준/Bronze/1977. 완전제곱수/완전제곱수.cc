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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<int> v;
	for (int i = 1; i <= 100; i++) {
		int temp = i * i;
		if (temp >= N && temp <= M)
			v.push_back(temp);
	}
	if (v.empty())
		cout << -1;
	else {
		int ans = 0;
		for (auto a : v) {
			ans += a;
		}
		cout << ans << endl << v[0];
	}
}
