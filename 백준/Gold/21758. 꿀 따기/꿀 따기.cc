#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define endl '\n'

int honey[100002] = { 0 };
int v[100002] = { 0 };
int range(int v[100002], int a, int b) {
	return v[b] - v[a];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> honey[i - 1];
		v[i] = v[i - 1] + honey[i-1];
	}
	int ans = 0;
	int case0 = range(v, 0, N);
	int case1 = case0 - honey[0];
	int case2 = case0 - honey[N-1];
	for (int i = 1; i < N; i++) { 
		ans = max(ans, case1 + range(v, i, N) - honey[i] * 2);
	}
	for (int i = 1; i < N-1; i++) {
		ans = max(ans, case2 + range(v, 0, i+1) - honey[i] *2 );
	}
	for (int i = 2; i < N; i++) {
		ans = max(ans, v[i] - v[1] + v[N - 1] - v[i - 1]);
	}
	cout<<ans;
}