#include <iostream>
#include <vector>
#define ll long long 
#define vll vector<ll>
#define fastio ios::sync_with_stdio(0);cin.tie(0)
#define endl '\n'
using namespace std;

void update(vll &tree, int index, ll diff){
	for(;index<tree.size();index+=(index&-index))
		tree[index]+=diff;
}
vll maketree(vll &arr){
	vll tree(arr.size());
	for(int i=1;i<=arr.size();i++){
		update(tree,i,arr[i]);
	}
	return tree;
}
ll sum(vll &tree, int idx){
	ll temp=0;
	while(idx){
		temp += tree[idx];
		idx -= (idx&-idx);
	}
	return temp;
}
ll rangesum(vll &tree, int left, int right){
	return sum(tree, right)-sum(tree, left-1);
}

int main(){
	fastio;
	int T;
	cin>>T;
	while(T--){
		int B,P,Q;
		cin>>B>>P>>Q;
		vll tree(B+1);
		for(int i=0; i<P+Q; i++){
			char c;
			int l, r;
			cin>>c>>l>>r;
			if(c=='P')
				update(tree, l,r);
			else if(c=='Q')
				cout<<rangesum(tree,l,r)<<endl;
		}
	}
}