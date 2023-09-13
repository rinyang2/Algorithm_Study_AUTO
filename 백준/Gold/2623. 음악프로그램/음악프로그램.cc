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
/*
int root[500001];
int find(int a) {
	if (a == root[a]) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (b < a)
		root[a] = b;
	else
		root[b] = a;
}
*/



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//bool kk[1001] = { false };
	int N, M;
	cin >> N >> M;
	vector<int> v[1001];
	vector<int> vv(N + 1);
	while (M--) {
		int k;
		cin >> k;
		vector<int> temp(k);
		for (int i = 0; i < k; i++) {
			cin >> temp[i];
			//kk[temp[i]] = true;
		}
		for (int i = 0; i < k - 1; i++) {
			v[temp[i]].push_back(temp[i + 1]);
			vv[temp[i + 1]]++;
		}
		temp.clear();
	}

	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (vv[i] == 0)
			q.push(i);

	}
	vector <int> ans;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto a : v[now]) {
			vv[a]--;
			if (vv[a] == 0) {
				q.push(a);
			}
		}
		ans.push_back(now);
	}
	if (ans.size() != N)
		cout << 0;
	else {
		for (auto a : ans) {
			//if (kk[a])
			cout << a <<endl;
		}
	}

}
