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

int N, K;
struct jewel {
	int wght;
	int value;
};

//무게순 오름차순 정렬
bool jewelCompare(jewel A, jewel B) {
	return A.wght < B.wght;
}
priority_queue<int> pq;
vector<jewel> v;
vector<int> backpack;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), jewelCompare);
	for (int i = 0; i < K; i++) {
		int a;
		cin >> a;
		backpack.push_back(a);
	}
	sort(backpack.begin(), backpack.end());

	long long ans = 0;
	//집어넣은 보석까지의 index
	int idx = 0;
	//모든 가방들에 대해 수행
	for (auto a : backpack) {
		while (idx < N && v[idx].wght <= a) {
			pq.push(v[idx].value);
			idx++;
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
		
	}
	cout << ans;
	return 0;
}
