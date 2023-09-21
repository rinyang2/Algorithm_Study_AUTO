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

long long int gcd(long long int a, long long int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

void solution() {
	long long int a, b;
	cin >> a >> b;
	long long int g = gcd(a, b);
	cout << a * b / g;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solution();
}