#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
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
	vector<int> assign(M+1);
	unordered_map<string, int> um;
	for(int i = 1; i<=M; i++){
		string s;
		cin>>s;
		um[s]=i;
	}
	for(int i = 1; i<= N; i++){
		int n;
		cin>>n;
		while(n--){
			string temp;
			cin>>temp;
			jobs[i].push_back(um[temp]);
		}
	}
	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(M+1);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	if(N==cnt)
		cout<<"YES";
	else{
		cout<<"NO"<<endl<<cnt;
	}
}