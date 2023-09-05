#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <unordered_map>
#define pii pair<int,int>
#define endl '\n'
using namespace std;

string s1, s2;

string revs(string s) {
	string temp = "";
	for (int i = s.length() - 1; i >= 0; i--) {
		temp += s[i];
	}
	return temp;
}

void sol(string s) {
	if (s.length() == s1.length()) {
		if (s == s1) {
			cout << 1;
			exit(0);
		}
		return;
	}
	string temp = revs(s);
	if (temp.back() == 'B') {
		temp.pop_back();
		sol(temp);
	}
	if (s.back() == 'A') {
		temp = s;
		temp.pop_back();
		sol(temp);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	
	
	cin >> s1 >> s2;
	
	sol(s2);
	cout << 0;
}