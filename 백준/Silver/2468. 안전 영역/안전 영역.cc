//you suck's code
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int N;
int arr[100][100] = { 0, };
int visited[100][100] = { 0, };
struct Node {
    int y, x;
};
queue<Node> q;
int rfind(int n) {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] > n && visited[i][j] == 0) {
                visited[i][j] = 1;
                ans++;
                q.push({ i,j });
                while (!q.empty()) {
                    Node now = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int nexty = now.y + dy[k];
                        int nextx = now.x + dx[k];
                        if (nexty < 0 || nextx < 0 || nextx >= N || nexty >= N) continue;
                        if (arr[nexty][nextx] <= n || visited[nexty][nextx] != 0) continue;
                        visited[nexty][nextx] = 1;
                        q.push({ nexty,nextx });
                    }
                }
                
            }
        }
    }
    return ans;
}
int main() {
    cin >> N;
    int mx = 0;
    //입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > mx) {
                mx = arr[i][j];
            }
        }
    }
    int temp = 0;
    
    for (int i = 0; i < mx; i++) {
        //visited 초기화
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                visited[j][k] = 0;
            }
        }
        int value = rfind(i);
        temp = max(temp, value);
    }
    cout << temp;
}