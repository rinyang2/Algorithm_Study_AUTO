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


int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int lp = 0, rp = 0;
	int arr[200001] = { 0 };
	int ans = 0;
	while (rp < N) {
		if (arr[v[rp]] < K) {
			arr[v[rp]]++;
			rp++;
		}
		else {
			arr[v[lp]]--;
			lp++;
		}
		
		ans = max(ans, rp - lp);
		//cout<< endl<<ans<<endl;
	}
	cout << ans;
}