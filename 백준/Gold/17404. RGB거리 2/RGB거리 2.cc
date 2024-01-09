#include<iostream>
#include<vector>
using namespace std;
#define INF 9999999
int main() {
	int N;
	cin >> N;
	int ans = INF;
	vector<vector<int>>v(N+1);
	for (int i = 1; i <= N; i++) {
		v[i].resize(3);
		for (int j = 0; j < 3; j++) {
			cin >> v[i][j];
		}
	}
	for(int st=0; st<3;st++){
		vector<vector<int>>dp(N+1);
		for (int i = 0; i < N+1; i++) {
			dp[i].resize(3);
		}
		for(int i = 0 ; i < 3; i++){
			if(i==st){
				dp[1][st]=v[1][st];
			}
			else{
				dp[1][i]=INF;
			}
		}
		for (int i = 2; i <= N; i++) {
			int r, g, b;
			r = min(dp[i - 1][1], dp[i - 1][2]) + v[i][0];
			g = min(dp[i - 1][0], dp[i - 1][2]) + v[i][1];
			b = min(dp[i - 1][1], dp[i - 1][0]) + v[i][2];
			dp[i] = { r,g,b };
		}
		for(int i = 0 ; i < 3; i++){
			if(i==st){
				continue;
			}
			ans = min(ans, dp[N][i]);
		}
	}
	cout<<ans;
}