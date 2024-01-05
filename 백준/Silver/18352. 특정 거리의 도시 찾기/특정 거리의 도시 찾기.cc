#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
	int N,M,K,X;
    cin>>N>>M>>K>>X;

    vector<vector<int>> v(N+1);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    vector<int> visited(N+1);
    for(int i=0;i<N+1;i++){
        visited[i]=-1;
    }
    vector<int> ans;
    queue<int> q;
    q.push(X);
    visited[X]=0;
    while(!q.empty()){
        int now=q.front();q.pop();
        if(visited[now]>K)
            continue;
        for(auto a:v[now]){
            if(visited[a]==-1){
                q.push(a);
                visited[a]=visited[now]+1;
                if(visited[a]==K){
                    ans.push_back(a);
                }
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(ans.size()==0){
        cout<<-1;
    }
    for(auto a: ans){
        cout<<a<<'\n';
    }
}