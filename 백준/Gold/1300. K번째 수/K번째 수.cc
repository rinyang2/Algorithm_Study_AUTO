#include<iostream>
#include<algorithm>
#include<vector>

#define endl '\n'
using namespace std;
long long N, K;
//n보다 작은 숫자의 개수를 return하는 함수
long long find(long long x) {
	long long cnt = 0;
	for (long long i = 1; i <= N; i++) {
		if (N*i < x) cnt += N;
		else {
			if (x%i == 0) cnt += (x / i) - 1;
			else cnt += (x / i);
		}
	}
	return cnt+1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> K;
	long long l = 1, r = K+1;
	long long mid;
	while (l < r - 1) {
		mid = (l + r) / 2;
		if (find(mid) <= K) {
			l = mid;
		}
		else {
			r = mid;
		}
	}
	cout << l;
}
