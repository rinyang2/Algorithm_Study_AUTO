#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){priority_queue<int,vector<int>,greater<>>pq;int N;cin>>N;
for(int i=0;i<N;i++){int T;cin>>T;pq.push(T);}
int ans=0;
while(!pq.empty()){ans=max(ans,pq.top()*N);N--;pq.pop();}
cout<<ans;
}