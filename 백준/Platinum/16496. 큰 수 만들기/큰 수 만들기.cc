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

bool fnc(string s1, string s2) {
	/*
	int a = s1.length(), b = s2.length();
	int temp = min(a, b);
	for (int i = 0; i < min(a, b); i++) {
		if (s1[i] == s2[i])
			continue;
		else
			return s1[i] > s2[i];
	}
	//s1이 더 긴 경우
	if (a > b) {
		return s1[b] > s2.back();

	}
	//s2가 더 긴 경우
	else if (a < b) {
		return s1.back() > s2[a];

	}
	else {
		return false;
	}
	*/
	if (s1 == s2)
		return false;
	return s1 + s2 > s2 + s1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin >> N;
	vector<string> v(N);
	bool b = true;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] != "0")
			b = false;
	}
	sort(v.begin(), v.end(), fnc);
	if (b)
		cout << 0;
	else {
		for (auto a : v) {
			cout << a;
		}
	}
	
}