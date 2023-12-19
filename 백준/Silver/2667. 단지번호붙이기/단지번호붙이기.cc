#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
struct coord {
	int y, x;
};
int main() {
	int N;
	cin >> N;
	vector<vector<int>>v(N);
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (auto a : s) {
			v[i].push_back(a - '0');
		}
	}
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (v[i][j] == 0)
				continue;
			int cnt = 1;
			queue<coord> q;
			q.push({ i,j });
			v[i][j] = 0;
			while (!q.empty()) {
				coord now = q.front(); q.pop();
				for (int i = 0; i < 4; i++) {
					int y = dy[i] + now.y, x = dx[i] + now.x;
					if (y < 0 || x < 0 || y >= N || x >= N)
						continue;
					if (v[y][x] == 1) {
						q.push({ y,x });
						v[y][x] = 0;
						cnt++;
					}
				}
			}
			answer.push_back(cnt);
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';
	for (auto a : answer) {
		cout << a << '\n';
	}
}