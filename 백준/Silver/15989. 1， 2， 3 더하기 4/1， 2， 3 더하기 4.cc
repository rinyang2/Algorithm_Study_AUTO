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
	int arr[10001];
	for (int i = 0; i < 10001; i++) {
		arr[i] = 1;
	}
	for (int i = 2; i < 10001; i++) {
		arr[i] += arr[i-2];
	}
	for (int i = 3; i < 10001; i++) {
		arr[i] += arr[i - 3];;
	}
	int T;
	cin >> T;
	while (T--) {
		int temp;
		cin >> temp;
		cout << arr[temp]<<endl;
	}
}