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

int root[100001];
bool non_qry[100001];

pii v[100001];

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
	int N, M, Q;
	cin >> N >> M >> Q;

	fill(root, root + 100001, -1);

	//간선정보 v
	
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = { a,b };
		non_qry[i] = true;
	}
	//쿼리정보 qry
	vector<int> qry(Q+1);

	for (int i = 1; i <= Q; i++) {
		cin >> qry[i];
		non_qry[qry[i]] = false;
	}
	for (int i = 1; i <= M; i++) {
		if (non_qry[i])Union(v[i].first, v[i].second);
	}

	long long ans = 0;
	for (int i = Q; i >= 1; i--) {
		int t = qry[i];
		int c = find(v[t].first);
		int d = find(v[t].second);
		if (c != d) {
			ans += ((long long)(root[c]) * (long long)(root[d]));
		}
		Union(c,d);
	}
	cout << ans<<endl;
	return 0;
}
