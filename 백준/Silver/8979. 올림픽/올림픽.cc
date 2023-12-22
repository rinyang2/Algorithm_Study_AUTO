#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct medal {
	int gold, silver, bronze;
	bool operator<(medal m) const {
		if (gold == m.gold) {
			if (silver == m.silver) {
				return bronze > m.bronze;
			}
			return silver > m.silver;
		}
		return gold > m.gold;
	}
};

int main() {
	int N, K;
	cin >> N >> K;
	vector<medal> v;
	medal m;
	for (int i = 0; i < N; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == K) {
			m = { b,c,d };
		}
		v.push_back({ b,c,d });
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < N; i++) {
		if (v[i].gold == m.gold && v[i].silver == m.silver && v[i].bronze == m.bronze) {
			cout << i + 1;
			break;
		}
	}
}