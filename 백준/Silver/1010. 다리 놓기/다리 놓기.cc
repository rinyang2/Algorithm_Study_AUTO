#include <iostream>
#include <vector>
using namespace std;
const int prime[] = { 2,3,5,7,11,13,17,19,23,29 };
int solution(int N, int M) {
	int arr[10] = { 0 };
	for (int i = M; i > N; i--) {
		int temp = i;
		for (int j = 0; j < 10;j++) {
			if (temp == 1)
				break;
			while (temp % prime[j] == 0) {
				temp /= prime[j];
				arr[j]++;
			}
		}
	}
	for (int i = 1; i <= M - N; i++) {
		int temp = i;
		for (int j = 0; j < 10; j++) {
			if (temp == 1)
				break;
			while (temp % prime[j] == 0) {
				temp /= prime[j];
				arr[j]--;
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < 10; i++) {
		//cout << prime[i] << " : " << arr[i] << endl;
		if (arr[i]) {
			while (arr[i]--) {
				ans *= prime[i];
			}
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		cout<<solution(N, M)<<'\n';
	}
}