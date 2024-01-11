#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl '\n'
const int dy[]={1,1,-1,-1,2,2,-2,-2}, dx[]={2,-2,2,-2,1,-1,1,-1};
struct coord{
    int y,x;
};

int bfs(){
    int l;
    cin>>l;
    coord st, ed;
    cin>>st.y>>st.x>>ed.y>>ed.x;
    queue<coord> q;
    vector<vector<int>>visited(l);
    for(int i = 0 ; i < l; i++){
        visited[i].resize(l);
    }
    visited[st.y][st.x] = 1;
    q.push(st);
    while(!q.empty()){
        coord now = q.front();q.pop();
        for(int i = 0 ; i < 8 ; i++){
            int y = dy[i]+now.y, x=dx[i]+now.x;
            if(y>=l||x>=l||y<0||x<0)
                continue;
            if(!visited[y][x]){
                visited[y][x]=visited[now.y][now.x]+1;
                if (y==ed.y && x==ed.x){
                    return visited[y][x]-1;
                }
                q.push({y,x});
            }
        }
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N;
    cin>>N;
    while(N--){
        cout<<bfs()<<endl;
    }
    
}