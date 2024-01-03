#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> v(n);
    for(int i = 0 ; i < n ; i++)
        cin>>v[i];
	vector<double> dp(n+1);
	dp[0] = v[0];
	double ans = 0;
	for (int i = 0; i <= n; i++) {
		dp[i]=max(dp[i-1]*v[i],v[i]);
        ans=max(ans,dp[i]);
	}
	printf("%.3f",ans);
	return 0;
}