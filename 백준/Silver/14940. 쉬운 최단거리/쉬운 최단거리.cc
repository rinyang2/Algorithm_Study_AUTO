#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>

#define endl '\n'
using namespace std;
const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };

struct coord {
	int y, x;
};
int N, M;
int arr[1000][1000];
int visited[1000][1000];
int main() {
	ios::sync_with_stdio(false); cin.tie(0);	
	cin >> N >> M;
	coord st;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			arr[i][j] = temp;
			visited[i][j] = -1;
			if (temp == 2) {
				st = { i,j };
			}
		}
	}
	queue<coord> q;
	visited[st.y][st.x] = 0;
	q.push(st);
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i], x = now.x + dx[i];
			if (y < 0 || x < 0 || y >= N || x >= M)
				continue;
			if (visited[y][x] == -1) {
				if (arr[y][x] == 1) {
					visited[y][x] = visited[now.y][now.x] + 1;
					q.push({ y,x });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				cout << visited[i][j]<<" ";
			}
		}
		cout << endl;
	}
}