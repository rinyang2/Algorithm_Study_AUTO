#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 301;
const int dy[] = { 1,-1,0,0 }, dx[] = { 0,0,1,-1 };
int arr[MAX][MAX];
int C, R;
int completed[MAX][MAX] = { 0 };
void input() {
	cin >> C >> R;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
}
void print(int arr[MAX][MAX]) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
}

struct coord {
	int y;
	int x;
	bool operator<(coord c) const {
		return arr[y][x] > arr[c.y][c.x];
	}
};

bool canfill(int y, int x) {
	bool all_lower = true;
	bool one_lower = true;
	int original = arr[y][x];
	for (int i = 0; i < 4; i++) {
		int yy = y + dy[i], xx = x + dx[i];
		//범위 초과인 경우 물을 채울 수 없음
		if (yy<0 or xx<0 or yy>=R or xx>=C)
			return false;
		int next = arr[yy][xx];
		if (original <= next)
			all_lower = false;
		if (original > next)
			one_lower = false;
	}
	if (all_lower) {
		completed[y][x] = 1;
		return false;
	}
	return one_lower;
}

int bfs(int y, int x) {
	vector <coord> vv;
	int meet_edge = 1;
	//방문처리
	int visited[MAX][MAX] = { 0 };
	queue<coord> q;
	visited[y][x] = 1;
	q.push({ y,x });
	vv.push_back({ y,x });
	//시작 노드의 높이
	int this_value = arr[y][x];
	//같은 높이의 노드들을 탐색하며 인근 노드 중 가장 낮은 높이를 찾는다
	int closest_min = INT32_MAX;
	while (!q.empty()) {
		coord t = q.front();
		q.pop();

		//현재 노드에서 상하좌우로 탐색한다
		for (int i = 0; i < 4; i++) {
			int yy = t.y + dy[i], xx = t.x + dx[i];
			
			//테두리를 마주한 경우 리턴
			if (yy < 0 or xx < 0 or yy >= R or xx >= C) {
				meet_edge = 0;
				continue;
			}
			int next = arr[yy][xx];
			//같은 높이인경우 queue에 넣고 탐색
			if (this_value == next && visited[yy][xx] == 0) {
				visited[yy][xx] = 1;
				vv.push_back({ yy,xx });
				q.push({ yy,xx });
			}
			//다른 높이인 경우 인근최소높이 갱신
			else {
				if (next < closest_min && next != this_value) {
					closest_min = next;
				}
			}
		}
	}
	int cnt = 0;
	if (closest_min <= this_value) {
		return 0;
	}

	if (meet_edge == 0) {
		for (auto a : vv) {
			completed[a.y][a.x] = 1;
		}
		return 0;
	}
	else {
		for (auto a : vv) {
			arr[a.y][a.x] = closest_min;
			cnt+= closest_min - this_value;
		}
	}

	return cnt;
}

void fill() {
	priority_queue <coord> pq;
	//상하좌우가 모두 자기보다 같거나 높은 노드들을 push
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (canfill(i, j)) {
				pq.push({ i,j});
			}
		}
	}

	int cnt = 0;
	
	while (!pq.empty()) {
		coord temp = pq.top(); pq.pop();
		if (completed[temp.y][temp.x] == 1)
			continue;
		int k = bfs(temp.y, temp.x);
		if (k){
			pq.push(temp);
			cnt += k;
			
		}

	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	input();
	fill();
}