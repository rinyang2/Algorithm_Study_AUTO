#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int root[10001];
int N, M;
struct node {
	int x;
	int y;
	int w;
	bool operator< (node n) {
		return w < n.w;
	}
};

int find(int a) {
	if (a == root[a])
		return a;
	return root[a] = find(root[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (b < a) {
		root[a] = b;
	}
	else {
		root[b] = a;
	}
}


vector <node> v;


int main() {
	cin >> N >> M;

	for (int i =  0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v.push_back({ a,b,c });
	}

	//Kruskal을 위해 가중치 기준 오름차순 정렬
	sort(v.begin(), v.end());

	

	for (int i = 0; i <= N; i++) {
		root[i] = i;
	}
	int cnt = 0;

	for (auto a : v) {
		if (find(a.x) != find(a.y)) {
			Union(a.x, a.y);
			cnt += a.w;
		}
	}
	
	cout << cnt;
}
