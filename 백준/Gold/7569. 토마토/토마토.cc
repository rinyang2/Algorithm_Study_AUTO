#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#define endl '\n'
using namespace std;

const int dy[]={1,-1,0,0,0,0}, dx[]={0,0,1,-1,0,0}, dz[]={0,0,0,0,1,-1};
struct coord{
    int z,y,x;
};

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int M, N, H;
    cin>>M>>N>>H;
    int zeros=0;
    queue<coord> q;
    vector<vector<vector<int>>> v(H);
    for(int i = 0 ; i < H ; i++){
        v[i].resize(N);
        for(int j = 0; j<N; j++){
            v[i][j].resize(M);
            for(int k = 0; k<M; k++){
                int temp;
                cin>>temp;
                v[i][j][k] = temp;
                if(temp==0){
                    zeros++;
                }
                else if(temp==1){
                    q.push({i,j,k});
                }
            }
        }
    }
    int ans = 0;
    while(!q.empty()){
        coord now = q.front();q.pop();
        for(int i = 0 ; i < 6;i++){
            int x=now.x+dx[i],y=now.y+dy[i], z=now.z+dz[i];
            if(x<0||y<0||z<0||x>=M||y>=N||z>=H)
                continue;
            if(v[z][y][x]==0){
                v[z][y][x] = v[now.z][now.y][now.x]+1;
                ans = max(ans, v[z][y][x]);
                q.push({z,y,x});
                zeros--;
            }
        }
    }
    
    if(zeros)
        cout<<-1;
    else{
        if (ans>0){
            cout<<ans-1;
        }
        else{
            cout<<0;
        }
    }
}