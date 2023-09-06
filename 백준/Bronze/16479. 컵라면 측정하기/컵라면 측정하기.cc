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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int k;
	cin >> k;
	double ans;
	double d1, d2;
	cin >> d1>> d2;

	if (d1 == d2) {
		cout<<k;
		return 0;
	}
	else {
		cout << k*k - ((d1 - d2) / 2)*((d1 - d2) / 2);
	}

}