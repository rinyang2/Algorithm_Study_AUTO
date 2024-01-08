#include <iostream>
#include <queue>
using namespace std;
#define endl '\n'
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m,Q;
    cin>>n>>m>>Q;
    vector<vector<int>>v(n+1);
    for(int i = 0;i<n+1;i++){
        v[i].resize(m+1);
    }
    int cnt = n*m;
    while(Q--){
        int Qtype;
        cin>>Qtype;
        if(Qtype==1){
            int dy,dx,y,x;
            cin>>dy>>dx>>y>>x;
            while(true){
                if(y<1||x<1||y>n||x>m)
                    break;
                if(v[y][x])
                    break;
                v[y][x]=1;
                cnt--;
                y=y+dy;
                x=x+dx;
            }
        }
        else if(Qtype==2){
            int y,x;
            cin>>y>>x;
            cout<<v[y][x]<<endl;
        }
        else if(Qtype==3){
            cout<<cnt<<endl;
        }
    }
}