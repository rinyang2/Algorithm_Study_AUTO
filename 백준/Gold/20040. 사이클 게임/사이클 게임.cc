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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		root[i] = i;
	}
	bool fst = true;
	int ans = 0;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b) && fst) {
			ans = i;
			fst = false;
		}
			
		Union(a, b);
	}
	cout << ans;
}
