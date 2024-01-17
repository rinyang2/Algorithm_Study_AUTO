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

int solution(int N, int M, int K){
	vector<vector<int>> jobs(N+1);
	vector<int> assign(M+1);
	for(int i=0;i<K;i++){
		int a,b;
		cin>>a>>b;
		jobs[a].push_back(b);
	}
	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(M+1);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int N, M, K1, K2;
	cin>>N>>M>>K1>>K2;
	if(solution(N,M,K1)<solution(N,M,K2))
		cout<<"네 다음 힐딱이";
	else
		cout<<"그만 알아보자";
}