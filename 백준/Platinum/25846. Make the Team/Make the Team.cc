#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;

bool dfs(int x, vector<vector<int>> &v, vector<bool> &done, vector<int> &assign){
	for(auto a: v[x]){
		if(done[a]) continue;
		done[a] = true;
		if(assign[a]==0||dfs(assign[a],v,done,assign)){
			assign[a]=x;
			return true;
		}
	}
	return false;
}

int solution(int N){
	vector<vector<int>> jobs(1001);
	vector<int> assign(1001);
	for(int i=1; i<=N;i++){
		int t;cin>>t;
		while(t--){
			int x; cin>>x;
			jobs[x].push_back(i);
		}
	}
	int cnt=0;
	for(int i = 1; i<=1001; i++){
		vector<bool> done(1001);
		if(dfs(i,jobs,done,assign))cnt++;
		if(cnt==N){
			return i+1;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N;
	cin>>N;
	cout<<solution(N);
}