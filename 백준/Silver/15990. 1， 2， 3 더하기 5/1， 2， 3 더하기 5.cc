#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int MOD = 1000000009;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    int dp[100001][3] = {{0, 0, 0}, {1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    for (int i = 4; i <= 100000; i++) {
        dp[i][0]=(dp[i-1][1] + dp[i-1][2]) % MOD;
        dp[i][1]=(dp[i-2][0] + dp[i-2][2]) % MOD;
        dp[i][2]=(dp[i-3][0] + dp[i-3][1]) % MOD;
    }
    while (T--) {
        int n;
        cin >> n;
        cout << ((dp[n][0] + dp[n][1]) % MOD + dp[n][2])%MOD << endl;
    }
    return 0;
}
