#include<iostream>
#include<vector>
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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin>>N>>M;
	vector<vector<int>> jobs(N+1);
	vector<int> assign(N+1);
	while(M--){
		int a,b;
		cin>>a>>b;
		jobs[a].push_back(b);
	}
	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(N+1);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	cout<<cnt<<endl;
}