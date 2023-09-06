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
	int N;
	cin >> N;
	vector<long long> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = INT64_MAX;
	int ans_ptr[3] = { 0,1,2 };
	//two-pointer N times(O(N^2))
	for (int i = 0; i < N - 2; i++) {
		int lp = i + 1;
		int rp = N - 1;
		long long cur = abs(v[i]+v[lp]+v[rp]);
		int temp_ptr[2] = {lp, rp};
		while (lp < rp && lp>i &&rp>i) {
			long long temp = v[i]+v[lp] + v[rp];
			if (abs(temp) < cur) {
				cur = abs(temp);
				temp_ptr[0] = lp;
				temp_ptr[1] = rp;
			}
			if (temp < 0) {
				lp++;
			}
			else {
				rp--;
			}

		}

		if (cur < ans) {
			ans_ptr[0] = i;
			ans_ptr[1] = temp_ptr[0];
			ans_ptr[2] = temp_ptr[1];
		}
		ans = min(ans, cur);
	}

	for (int i = 0; i < 3; i++) {
		cout << v[ans_ptr[i]] << " ";
	}
}