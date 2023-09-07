#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 100001;
vector <vector<int>> v[MAX];
int visited[MAX] = { 0 };
int N;

void reset() {
	for (int i = 0; i < MAX; i++) {
		visited[i] = 0;
	}
}

//최대거리를 담을 변수
int max_distance = 0;
//최대거리를 찾을 수 있는 노드의 값
int target_node;

bool end(int node) {
	for (auto a : v[node]) {
		if (visited[a[0]] == 0) {
			return false;
		}
	}
	return true;
}
//dfs를 이용해 특정 node에서 모든 leaf까지의 거리를 찾은 후, 최대거리를 갱신함
void dfs(int node, int cost) {
	visited[node] = 1;
	if (v[node].size() == 0 or end(node)) {
		if (cost > max_distance) {
			max_distance = cost;
			target_node = node;
		}
		return;
	}
	for (auto a : v[node]) {
		if (visited[a[0]] == 0) {
			dfs(a[0], cost + a[1]);
		}
	}
}

int main() {
	//트리 정점의 개수가 주어진다
	cin >> N;
	//트리를 입력받는다
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	//print();

	//임의의 점에서 최대거리인 노드를 찾고
	dfs(1, 0);
	//찾은 노드에서 다시 최대 거리인 노드를 찾으면 트리 특성상 찾을 수 있는 가장 먼 거리가 된다
	reset();
	dfs(target_node, 0);
	//정답을 출력한다
	cout << max_distance;
}