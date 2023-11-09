#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;
int box[8] = { 0, };
int N,M;
int visited[9] = { 0, };
void dfs(int now) {
	if (now == M) {
		for (int i = 0; i < M; i++)
			cout << box[i] << " ";
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		visited[i]++;
		box[now] = i;
		dfs(now + 1);
		visited[i]--;
	}
}

int main()
{
	//freopen("Text.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	dfs(0);



}