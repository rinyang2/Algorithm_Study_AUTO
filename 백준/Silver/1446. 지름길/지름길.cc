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

struct node {
	int from;
	int to;
	int cost;
	bool operator<(node n) {
		if (from == n.from)
			if (to == n.to)
				return cost < n.cost;
			else
				return to < n.to;
		return from < n.from;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, D;
	cin >> N >> D;
	vector<node> v;
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}
	sort(v.begin(), v.end());

	int dp[10001];
	for (int i = 0; i < D+1; i++) {
		dp[i] = i;
	}
	dp[0] = 0;
	for (auto a : v) {
		if (dp[a.from] + a.cost < dp[a.to])
			dp[a.to] = dp[a.from] + a.cost;
		int temp = 0;
		for (int i = a.to; i <= D; i++) {
			if (dp[a.to] + temp < dp[i])
				dp[i] = dp[a.to] + temp;
			temp++;
		}
	}
	cout << dp[D];
}