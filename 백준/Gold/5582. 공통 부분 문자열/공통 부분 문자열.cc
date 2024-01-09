#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	string s1,s2;
	cin>>s1>>s2;
	int y=s1.length(), x=s2.length();
	vector<vector<int>> dp(y+1);
	for(int i = 0 ; i < y+1; i++){
		dp[i].resize(x+1);
	}
	int ans = 0;
	for(int i = 1 ; i <= y ; i++){
		for(int j = 1 ; j <= x; j++){
			if(s1[i-1]==s2[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
				ans = max(ans, dp[i][j]);
			}
		}
	}
	cout<<ans;
}