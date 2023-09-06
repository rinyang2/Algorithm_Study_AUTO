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

double W, H, X, Y, P;

bool inlink(int x1, int y1) {
	double r = H / 2;
	if ((X - x1)*(X - x1) + (Y+r - y1)*(Y+r - y1) <= r * r)
		return true;
	if ((X + W - x1)*(X + W - x1) + (Y + r - y1)*(Y + r - y1) <= r * r)
		return true;
	if (x1 <= X + W && y1 <= Y + H && x1 >= X && y1 >= Y)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> W >> H >> X >> Y >> P;
	int ans = 0;
	while (P--) {
		int a, b;
		cin >> a >> b;
		ans += inlink(a, b);
	}
	cout << ans;
}