#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		if (i == 0) {
			v[i] = temp;
		}
		else {
			v[i] = v[i - 1] + temp;
		}
	}
	int answer = INT32_MIN;
	for (int i = K - 1; i < N; i++) {
		int temp;
		if (i == K-1) {
			temp = 0;
		}
		else {
			temp = v[i - K];
		}
		answer = max(answer, v[i] -temp);
	}
	cout << answer;
}