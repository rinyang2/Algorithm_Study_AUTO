#include<iostream>
#include<vector>
#include<algorithm>
#define endl '\n'
using namespace std;

bool dfs(int x, vector<vector<int>> &v, vector<bool> &done, vector<int> &assign){
	done[x] = true;
	for(auto a: v[x]){	
		if(assign[a]==-1||(!done[assign[a]]&&dfs(assign[a],v,done,assign))){
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
	while(T--){
		int N, M;
		cin>>N>>M;
		vector<vector<int>> v(N);
		vector<int> assign(N,-1);
		while(M--){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
		}
		int cnt=0;
		for(int i = 0; i<N; i++){
			vector<bool> done(N);
			if(dfs(i,v,done,assign)) cnt++;
		}
		cout<<cnt<<endl;	
	}
	
}