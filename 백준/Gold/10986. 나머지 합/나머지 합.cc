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
	vector<long long> v(N + 1);
	v[0] = 0;
	vector<long long> vm(M);
	vm[0] = 1;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		v[i] = v[i - 1] + temp;
		vm[v[i] % M] ++;
	}
	long long cnt = 0;
	for (auto a : vm) {
		cnt += a * (a - 1) / 2;

	}
	cout <<cnt;
}