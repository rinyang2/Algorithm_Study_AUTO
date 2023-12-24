#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
const int MOD = 1000000009;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> v(N+1);
    for(int i = 1 ; i <= N ; i++){
        cin>>v[i];
    }
    vector<vector<int>>dp(N+1);
    dp[0] = {0,0};
    dp[1] = {v[1],0};
    for(int i = 2; i<=N;i++){
        int two, one;
        one = max(dp[i-2][0],dp[i-2][1])+v[i];
        two = dp[i-1][0]+v[i];
        dp[i]={one,two};
    }
    cout<<max(dp[N][0],dp[N][1]);
}
