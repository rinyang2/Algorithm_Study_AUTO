#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
struct coord {
	int y, x, cnt;
};
int main() {
	int M, N;
	cin >> M >> N;
	vector<vector<int>> v(N);
	queue<coord> q;
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1)
				q.push({ i,j,1});
		}
	}
		while (!q.empty()) {
			coord now = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int y = dy[i] + now.y, x = dx[i] + now.x;
				if (y < 0 || x < 0 || y >= N || x >= M)
					continue;
				if (v[y][x] == -1)
					continue;
				if (v[y][x] == 0 || v[y][x] > v[now.y][now.x] + 1) {
					v[y][x] = now.cnt + 1;
					q.push({ y,x, now.cnt+1});
				}
			}
		}
	int ans = 0;
	for (auto a : v) {
		for (auto b : a) {
			if (b == 0) {
				cout << -1;
				return 0;
			}
			ans = max(ans, b);
		}
	}
	cout << ans - 1;
}