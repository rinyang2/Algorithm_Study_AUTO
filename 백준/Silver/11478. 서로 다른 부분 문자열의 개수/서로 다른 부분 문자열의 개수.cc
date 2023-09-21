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



void solution() {
	string s;
	cin >> s;
	unordered_map<string, int> um;
	for (int i = 1; i <= s.length(); i++) {
		for (int j = 0; j <= s.length() - i; j++) {
			um[s.substr(j, i)] = 1;
		}
	}
	int cnt = 0;
	cout << um.size();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solution();
}