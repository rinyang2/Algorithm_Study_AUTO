#include <iostream>
#include <vector>
#define endl '\n'
#define ll long long
#define fastio ios::sync_with_stdio(0);cin.tie(0)
using namespace std;
void update(vector<ll>&tree,ll idx, ll diff){
    for(;idx<tree.size();idx+=(idx&-idx))
        tree[idx]+=diff;
}
vector<ll> maketree(vector<ll>&v){
    vector<ll>tree(v.size());
    for(int i=1;i<=v.size();i++)
        update(tree,i,v[i]);
    return tree;
}
ll sum(vector<ll>&tree,ll idx){
    ll temp=0;
    while(idx){
        temp+=tree[idx];
        idx-=(idx&-idx);
    }
    return temp;
}
ll rangesum(vector<ll>&tree,ll left, ll right){
    return sum(tree,right)-sum(tree,left-1);
}
void qry(vector<ll>&arr, vector<ll>&tree){
    ll x,y,a,b;
    cin>>x>>y>>a>>b;
    ll diff=b-arr[a];
    cout<<rangesum(tree,min(x,y),max(x,y))<<endl;
    update(tree,a,diff);
    arr[a]=b;
}
int main(){
    fastio;
    int N,Q;
    cin>>N>>Q;
    vector<ll> arr(N+1);
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    vector<ll> tree=maketree(arr);
    while(Q--)
            qry(arr,tree);
}