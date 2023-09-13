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
	int N, K;
	cin >> N>>K;
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		if (N%i == 0)
			v.push_back(i);
	}
	if(K<=v.size())
		cout << v[K-1];
	else {
		cout << 0;
	}
}
