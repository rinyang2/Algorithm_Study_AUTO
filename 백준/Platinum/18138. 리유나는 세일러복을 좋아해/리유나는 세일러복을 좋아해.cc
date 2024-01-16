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

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M;
	cin>>N>>M;
	vector<vector<int>> jobs(N+1);
	vector<int> assign(M+1);

	vector<int> left(N+1);
	vector<int> right(M+1);
	for(int i=1;i<=N;i++){
		cin>>left[i];
	}
	for(int i=1;i<=M;i++){
		cin>>right[i];
	}
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			int now=right[j];
			int w=left[i];
			if((now*2>=w && now*4<=w*3)||(now>=w&&now*4<=w*5)){
				jobs[i].push_back(j);
			}
		}
	}

	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(M+1);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	cout<<cnt;
}