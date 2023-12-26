#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
#define endl '\n'
using namespace std;

const int dy[]={1,-1,0,0}, dx[]={0,0,1,-1};
struct coord{
    int y,x;
};

int bfs(vector<vector<int>> &v,int n){
    int cnt = 0;
    int N = v.size();
    vector<vector<int>> visited(N);
    for(int i = 0 ; i<N ; i++){
        visited[i].resize(N);
    }
    for(int i = 0;i<N;i++){
        for(int j =0 ;j<N; j++){
            if (v[i][j]>n && visited[i][j]==0){
                cnt++;
                queue<coord>q;
                visited[i][j]=1;
                q.push({i,j});
                while(!q.empty()){
                    coord now =q.front();q.pop();
                    for(int k = 0 ; k<4;k++){
                        int y = now.y+dy[k], x = now.x+dx[k];
                        if(y<0||x<0||y>=N||x>=N)
                            continue;
                        if(v[y][x]>n && visited[y][x]==0){
                            visited[y][x]=1;
                            q.push({y,x});
                        }
                    }
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<vector<int>> v(N);
    for(int i=0;i<N;i++){
        v[i].resize(N);
        for(int j=0;j<N;j++)
            cin>>v[i][j];
    }
    int ans = 0;
    for(int i = 0 ; i <= 100; i++){
        ans = max(ans, bfs(v,i));
    }
    cout<<ans;
}

