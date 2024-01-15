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
	int T;
	cin>>T;
	for(int tc = 1; tc<=T; tc++){
		int N, M;
		cin>>M>>N;
		vector<vector<int>> jobs(N+1);
		vector<int> assign(M+1);
		for(int i = 1; i<= N; i++){
			int n;
			cin>>n;
			while(n--){
				int temp;
				cin>>temp;
				jobs[i].push_back(temp);
			}
		}
		int cnt=0;
		for(int i = 1; i<=N; i++){
			vector<bool> done(M+1);
			if(dfs(i,jobs,done,assign)) cnt++;
		}
		cout<<"Data Set "<<tc<<":"<<endl;
		cout<<cnt<<endl;
		cout<<endl;
	}
	
}