#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath> // <-- ceil,floor,round
#include<unordered_map>
#include<stack>
#define endl '\n'
#include<set>
using namespace std;
int N, M;
int map[300][300];
struct node {
	int i;
	int j;
	int cost;
};

struct fun {
	bool operator()(node left, node right) {
		if (left.cost > right.cost)
			return true;
		else
			return false;
	}
};

priority_queue<node, vector<node>, fun>pq;
unordered_map<int, int>uom;
int answer;
void floodfill(node now) {
	int visited[300][300] = { 0, };
	int i = now.i;
	int j = now.j;
	int cost = now.cost;

	queue<node>q;
	visited[i][j] = 1;
	q.push({ i,j,0 });
	int di[] = { 0,0,1,-1 };
	int dj[] = { 1,-1,0,0 };

	while (!q.empty()) {
		node a= q.front(); q.pop();
		int ii = a.i;
		int jj = a.j;
		
		for (int k = 0; k < 4; k++) {
			int ni = di[k] + ii;
			int nj = dj[k] + jj;

			if (ni <= 0 or ni >= N - 1 or nj <= 0 or nj >= M - 1)
				continue;
			
			if (visited[ni][nj] == 1)
				continue;
			auto it = uom.find(ni*M + nj);
			if (it == uom.end())
				continue;

			visited[ni][nj] = 1;
			uom.erase(it->first);
			if (map[ni][nj] >= cost) {
				pq.push({ ni,nj,map[ni][nj] });
				continue;
			}
			answer += (cost - map[ni][nj]);
			q.push({ ni,nj });
		}
	}


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (i == 0 or j == 0 or i==N-1 or j==M-1) {
				pq.push({ i,j,map[i][j] });
			}
			else
				uom[i*M + j];
		}
	}
	


	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		floodfill({ now });

	}

	cout << answer;
	return 0;
}