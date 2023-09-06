#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
const int dy[] = { 0,0,1,-1 }, dx[] = { 1,-1,0,0 };
using namespace std;



int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	int arr[102][102] = { 0 };
	cin >> N >> M;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				cnt += 2;
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j<= M; j++) {
			for (int k = 0; k < 4; k++) {
				int y = dy[k] + i, x = dx[k] + j;
				if (arr[i][j] - arr[y][x] > 0) {
					cnt += arr[i][j] - arr[y][x];
				}
			}
		}
	}
	cout << cnt;
}