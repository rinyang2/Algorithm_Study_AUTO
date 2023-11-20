#include <iostream>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int E, S, M;
	cin >> E >> S >> M;
	register int cnt = 1;
	while (true) {
		if (cnt % 15 == E % 15 and cnt % 28 == S % 28 and cnt % 19 == M % 19) {
			cout << cnt;
			break;
		}
		cnt++;
	}
}
