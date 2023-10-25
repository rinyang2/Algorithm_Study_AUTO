#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define endl '\n'
using namespace std;
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
struct coord{
	int y, x;
};
void debug(vector<vector<int>> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int bfs(vector<vector<int>> v, vector<coord> virus, int zeros) {

	int cnt = 0;
	queue<coord> q;
	vector<vector<int>> visited(v.size());
	for (int i = 0; i < v.size(); i++) {
		visited[i].resize(v[0].size());
	}
	for (coord c : virus) {
		visited[c.y][c.x] = 2;
		q.push(c);
	}
	while (!q.empty()) {
		coord now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int y = now.y + dy[i], x = now.x + dx[i];
			if (y < 0 || x < 0 || y >= v.size() || x >= v[0].size())
				continue;
			if (visited[y][x] == 0 && v[y][x] == 0) {
				visited[y][x] = 2;
				q.push({ y,x });
				cnt++;
			}
		}
	}
	
	return zeros - cnt-3;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> v(N);
	vector<coord> virus;
	vector<coord> ety;
	int zeros=0;
	for (int i = 0; i < N; i++) {
		v[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> v[i][j];
			if (v[i][j] == 2) {
				virus.push_back({ i,j });
			}
			else if (v[i][j] == 0) {
				zeros++;
				ety.push_back({ i,j });
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < ety.size(); i++) {
		coord a = ety[i];v[a.y][a.x] = 1;
		for (int j = i+1; j < ety.size(); j++) {
			coord b = ety[j];v[b.y][b.x] = 1;
			for (int k = j+1; k < ety.size(); k++) {
				coord c = ety[k];v[c.y][c.x] = 1;
				ans = max(ans, bfs(v, virus, zeros));
				v[c.y][c.x] = 0;
			}
			v[b.y][b.x] = 0;
		}
		v[a.y][a.x] = 0;
	}
	cout << ans;
}
