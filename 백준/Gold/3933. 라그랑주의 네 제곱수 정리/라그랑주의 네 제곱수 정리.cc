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

const int MAXSIZE = 1 << 15;
int arr[MAXSIZE][4] = { 0 };
void setup() {
	for (int i = 1; i*i<MAXSIZE; i++) {
		int ipow = i * i;
		arr[ipow][0] = 1;
		for (int j = ipow; j < MAXSIZE; j++) {
			arr[j][1] += arr[j - ipow][0];
			arr[j][2] += arr[j - ipow][1];
			arr[j][3] += arr[j - ipow][2];
		}
	}
	
}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	setup();
	while (1) {
		int temp;
		cin >> temp;
		if (temp == 0)
			break;
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans += arr[temp][i];
		}
		cout << ans << endl;
	}
	
}