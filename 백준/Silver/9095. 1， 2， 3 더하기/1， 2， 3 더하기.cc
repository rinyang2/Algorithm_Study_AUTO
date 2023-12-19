#include <iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	int arr[12] = { 1,1,2, };
	for (int i = 3; i < 12; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		cout << arr[temp] << '\n';
	}
}