#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> Dn(N+1);
		for (int i = 1; i <= N; i++) {
			cin >> Dn[i];
		}

		vector<vector<int>>v(N+1);

		vector<int> vv(N + 1);

		queue<int> q;

		for (int i = 0; i < K; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			vv[b]++;
		}

		int W;
		cin >> W;


		for (int i = 1; i <= N; i++) {
			if (vv[i] == 0) {
				q.push(i);
			}
		}
	
		vector<int> answer(N + 1);
		while (vv[W] > 0) {
			int temp = q.front(); q.pop();
			for (auto a : v[temp]) {
				answer[a] = max(answer[a], answer[temp] + Dn[temp]);
				if (--vv[a] == 0) {
					q.push(a);
				}
			}
		}
		
		
		cout << answer[W] + Dn[W] << endl;
	}
}