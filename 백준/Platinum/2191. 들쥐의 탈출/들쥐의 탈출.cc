#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl '\n'
using namespace std;

struct coord{
	double x,y;
};

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
	int N,M;
	double S,V;
	cin>>N>>M>>S>>V;
	vector<vector<int>> jobs(N+1);
	vector<int> assign(M+1);
	vector<coord> mouse(N+1);
	vector<coord> hole(M+1);
	for(int i=1;i<=N;i++){
		double x,y;
		cin>>x>>y;
		mouse[i]={x,y};
	}
	for(int i=1;i<=M;i++){
		double x,y;
		cin>>x>>y;
		hole[i]={x,y};
	}
	for(int i=1;i<=N;i++){
		double x=mouse[i].x, y=mouse[i].y;
		for(int j=1;j<=M;j++){
			double temp=sqrt((x-hole[j].x)*(x-hole[j].x)+(y-hole[j].y)*(y-hole[j].y));
			if(temp/V <= S){
				jobs[i].push_back(j);
			}
		}
	}
	int cnt=0;
	for(int i = 1; i<=N; i++){
		vector<bool> done(M+1);
		if(dfs(i,jobs,done,assign)) cnt++;
	}
	cout<<N-cnt<<endl;
}