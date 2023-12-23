#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
const int MOD = 1000000009;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    int dp[1000001] = {0,1,2,4};
    for (int i = 4; i <= 1000000; i++) {
        dp[i] = ((dp[i-3]+dp[i-2])%MOD+dp[i-1])%MOD;
    }
    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}
