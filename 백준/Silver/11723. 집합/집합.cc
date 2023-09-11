#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
using namespace std;

bool b[21] = { false };
void solve() {
	string s;
	int n;
	cin >> s;
	if (s == "empty") {
		for (int i = 0; i <= 20; i++) {
			b[i] = false;
		}
		return;
	}
	else if (s == "all") {
		for (int i = 0; i <= 20; i++) {
			b[i] = true;
		}
		return;
	}
	cin >> n;
	if (s == "add") {
		b[n] = true;
	}
	else if (s == "check") {
		cout << b[n]<<endl;
	}
	else if (s == "remove") {
		b[n] = false;
	}
	else if (s == "toggle") {
		b[n] = !b[n];
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int M;
	cin >> M;
	while (M--) {
		solve();
	}
}