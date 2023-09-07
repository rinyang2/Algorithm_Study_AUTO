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

struct coord {
	double x;
	double y;
};



void func(coord my_ball, coord target, coord hole) {

}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<string> vs(N);
	vector<int> vi(N);
	for (int i = 0; i < N; i++) {
		cin >> vs[i]>>vi[i];
	}
	while (M--) {
		int temp;
		cin >> temp;
		cout << vs[lower_bound(vi.begin(), vi.end(), temp) - vi.begin()] << endl;
	}
}