#include<iostream>
#include<unordered_map>
#include<vector>
#define endl '\n'
using namespace std;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;
	unordered_map<int, bool> um;
	while (N--) {
		int temp;
		cin >> temp;
		um[temp] = true;
	}
	int M;
	cin >> M;
	while (M--) {
		int temp;
		cin >> temp;
		if (um[temp]) {
			cout << 1 <<endl;
		}
		else {
			cout << 0 <<endl;
		}
	}
}
