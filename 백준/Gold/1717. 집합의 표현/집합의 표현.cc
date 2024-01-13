#include <iostream>
using namespace std;
#define endl '\n'
int root[1000001];
int find(int a) {
	if (a == root[a]) return a;
	return root[a] = find(root[a]);
}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (b < a)
		root[a] = b;
	else
		root[b] = a;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin>>n>>m;
    for(int i = 0 ; i <=n; i++){
        root[i] = i;
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a){
            if(find(b)==find(c))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else{
            Union(b,c);
        }
    }
    
}