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
	int G, P;
	cin >> G >> P;
	for (int i = 0; i <= G; i++) {
		root[i] = i;
	}
	int cnt = 0;
	while (P--) {
		int temp;
		cin >> temp;
		if (find(temp) == 0) {
			cout<<cnt;
			return 0;
		}
		Union(find(temp), find(temp) - 1);
		cnt++;
		
	}
	cout << cnt;
}
