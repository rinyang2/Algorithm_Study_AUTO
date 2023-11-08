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

int root[200001];
bool visited[200001];
vector<vector<int>> v;

int find(int a) {
	if (root[a]<0) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[a] += root[b];
	root[b] = a;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin >> N >> M;
	fill(root, root + 200001, -1);
	//간선정보 v
	v.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//쿼리정보 qry
	vector<int> qry(N);
	for (int i = 0; i < N; i++) {
		cin >> qry[i];
	}
	int cnt = 1;
	//정답벡터 ans
	vector<bool> ans;
	for (int i = N - 1; i >= 0; i--) {
		cnt++;
		for (auto a : v[qry[i]]) {
			if(visited[a])
				Union(a, qry[i]);
		}
		if (-root[find(qry[i])] == N-i)
			ans.push_back(true);
		else
			ans.push_back(false);
		visited[qry[i]] = true;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}
