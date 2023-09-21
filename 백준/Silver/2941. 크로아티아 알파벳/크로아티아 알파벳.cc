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
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'c') {
			if (i != s.length() - 1 && (s[i + 1] == '=' || s[i + 1] == '-')) {
				i++;
			}
		}
		else if (s[i] == 'd') {
			if (i != s.length() - 2 && s[i + 1] == 'z'&& s[i + 2] == '=') {
				i+=2;
			}
			else if (i != s.length() - 1 &&  s[i + 1] == '-') {
				i++;
			}
		}
		else if (s[i] == 'l' || s[i] == 'n') {
			if (i != s.length() - 1 && (s[i + 1] == 'j')) {
				i++;
			}
		}
		else if (s[i] == 's' || s[i] == 'z') {
			if (i != s.length() - 1 && (s[i + 1] == '=')) {
				i++;
			}
		}
		cnt++;
	}
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solution();
}