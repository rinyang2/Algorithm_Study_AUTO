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

int solution() {
	string s;
	cin >> s;
	bool arr[26] = { false };
	arr[s[0] - 'a'] = true;
	for (int i = 1; i < s.length(); i++) {
		if (s[i] != s[i - 1] && arr[s[i] - 'a'] == true)
			return 0;
		arr[s[i]-'a'] = true;
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	int ans = 0;
	while (N--) {
		ans += solution();
	}
	cout << ans;
}