#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
#define ll long long
using namespace std;

//Initialize Segment Tree
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end){
    if(start==end) return tree[node]= arr[start];
    int mid = (start+end)/2;
    return tree[node] = init(arr,tree,node*2,start,mid) + init(arr,tree,node*2+1,mid+1,end);
}

//Return prefix sum from left to right
ll sum(vector<ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start)return 0;
    if(left<=start && end<=right) return tree[node];
    int mid = (start+end)/2;
    return sum(tree, node*2,start, mid, left, right)+sum(tree, node*2+1, mid+1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int index, ll diff){
        if(index<start || index>end) return;
        tree[node] += diff;
        int mid=(start+end)/2;
        if(start!=end){
                update(tree, node*2, start, mid, index, diff);
                update(tree, node*2+1, mid+1, end, index, diff);
        }
}
/* //debug code(prints full tree)
void printtree(vector<ll> &tree, int n){
    int flag = 2;
    for(int i = 1; i<n; i++){
        cout<<tree[i]<<" ";
        int temp = i;
        if (i==flag-1){
                cout<<endl;
                flag*=2;
        }
    }
}*/

int main(){
  fastio;
  //input
    int N,M,K;
    cin>>N>>M>>K;
    vector<ll> arr(N);
  for(int i = 0;i<N;i++){
            cin>>arr[i];
    }
  //create segment tree
    int treesize = 1<<(int(ceil(log2(N)))+1);
    vector<ll> segtree(treesize);
    init(arr,segtree,1,0,N-1);
 
    int i = M+K;
 
    while(i--){
        int qry;
        cin>>qry;
        if(qry==2){
                int a,b;
                cin>>a>>b;
                cout<<sum(segtree,1,0,N-1,a-1,b-1)<<endl;
        }
        if(qry==1){
            int a;
            ll b;
            cin>>a>>b;
            a--;
            ll diff = b-arr[a];
            arr[a]=b;
            update(segtree, 1, 0, N-1, a, diff);
        }
    //debug part
        //if(qry==0){
        //        printtree(segtree, treesize);
        //}
    }
}