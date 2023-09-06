#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
using namespace std;


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int l = s.length();
	int a = 0;
	for (char c : s) {
		if (c == 'a') {
			a++;
		}
	}
	s += s;
	int b = 0;
	for (int i = 0; i < a; i++) {
		if (s[i] == 'b')
			b++;
	}
	int ans = INT32_MAX;
	for (int i = 0; i < l; i++) {
		if (s[i] == 'b')
			b--;
		if (s[a + i] == 'b')
			b++;
		ans = min(ans, b);
	}
	cout << ans;
}