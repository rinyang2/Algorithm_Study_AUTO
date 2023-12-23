#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include<algorithm>

#define endl '\n'
using namespace std;
const int dy[]={0,0,1,-1}, dx[] = {1,-1,0,0};

struct coord{
    int y,x;
    bool fire;
};
int solution(){
    int w, h;
    cin>>w>>h;
    vector<vector<char>> v(h);
    coord start;
    vector<coord> fire;
    for(int i = 0 ; i < h ; i++){
        v[i].resize(w);
        for(int j = 0 ; j < w ; j++){
            cin>>v[i][j];
            if(v[i][j]=='@')
                start={i,j,false};
            if(v[i][j]=='*')
                fire.push_back({i,j,true});
        }
    }
    vector<vector<int>> visited(h);
    for(int i = 0;i<h;i++){
        visited[i].resize(w);
    }
    queue<coord> q;
    
    for(coord a: fire){
        q.push(a);
        visited[a.y][a.x] = -1;
    }
    q.push(start);
    visited[start.y][start.x] = 1;
    while(!q.empty()){
        coord now = q.front();q.pop();
        for(int i=0; i<4; i++){
            int y = now.y+dy[i], x = now.x+dx[i];
            if(y<0||x<0||y>=h||x>=w){
                if(!now.fire){
                    return visited[now.y][now.x];
                }
                else
                    continue;
            }
            if(v[y][x]=='#')
                continue;
            if(visited[y][x]==0){
                if(now.fire){
                    visited[y][x]=visited[now.y][now.x]-1;
                    q.push({y,x,true});
                }
                else{
                    visited[y][x] = visited[now.y][now.x]+1;
                    q.push({y,x,false});
                }
            } 
        }
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        int ans = solution();
        if(ans==-1){
            cout<<"IMPOSSIBLE"<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}