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
	vector<vector<int>> jobs(2*N+1);
	vector<int> assign(1001);
	for(int i = 1; i<= N; i++){
		int n;
		cin>>n;
		while(n--){
			int temp;
			cin>>temp;
			jobs[i].push_back(temp);
			jobs[i+N].push_back(temp);
		}
	}
	int cnt=0;
	for(int i = 1; i<=N*2; i++){
		vector<bool> done(2001);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	cout<<cnt<<endl;
}