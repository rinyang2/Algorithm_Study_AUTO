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

void solution(){
	int N,M;
	cin>>N>>M;
	vector<vector<int>> left(N+1);
	vector<int> right(N+1);
	for(int i=1;i<=M;i++){
		int a,b;
		cin>>a>>b;
		if(a%2==b%2) continue;
		if(a%2)
			left[a].push_back(b);
		else
			left[b].push_back(a);
	}
	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(N+1);
		if(dfs(i,left,done,right))cnt++;
	}
	cout<<cnt*2+1*(cnt*2!=N);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	solution();
}