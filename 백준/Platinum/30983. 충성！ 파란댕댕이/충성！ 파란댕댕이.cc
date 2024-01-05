#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MOD = 1000000009;
#define ll long long
#define vvi vector<vector<ll>>

/*
    벡터를 4*N^2사이즈로 구현 후 4개 사분면으로 나눠 생각하자
    4사분면에 1분 도로의 연결상태가 인접행렬로 들어가고
    1사분면에 2분 도로의 연결상태가 인접행렬로 들어간다
    3사분면에 단위행렬이 들어가있기 때문에
    2사분면에 1분전 데이터가 들어가게 되기 때문에
    해당 행렬을 거듭제곱하면 답을 빠르게 구할 수 있을 것이다 
*/

vvi matrixmul(vvi v1, vvi v2){
    int size = v1.size();
    vvi res(size);
    for(int i = 0 ; i < size; i++){
        res[i].resize(size);
    }
    for(int i = 0; i<size; i++){
        for(int j = 0 ; j < size; j++){
            for(int k = 0 ; k<size; k++){
                res[i][j]+=(v1[i][k]*v2[k][j])%MOD;
            }
            res[i][j]%=MOD;
        }
    }
    return res;
}
vvi matrixpow(vvi v, int n){
    int size=v.size();
    //단위행렬
    vvi res(size);
    for(int i=0; i<size; i++){
        res[i].resize(size);
        res[i][i]=1;
    }
    while(n>0){
        if(n%2==1){
            res=matrixmul(res,v);
        }
        n/=2;
        v=matrixmul(v,v);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
	int N,M,T;
    cin>>N>>M>>T;
    //인접행렬을 담기 위한 벡터
    vvi v(N*2);
    for(int i=0;i<N*2;i++){
        v[i].resize(N*2);
    }
    //3사분면에 단위행렬 채워넣기
    for(int i=N;i<N*2;i++){
        v[i][i-N]=1;
    }
    //입력을 받아 행렬을 변환하고, 거듭제곱 시킬 준비를 한다
    for(int i=0;i<M;i++){
        int a,b,c,d;
        cin>>a;
        if(a==1){
            cin>>b>>c;
            b--;c--;
            v[b+N][c+N]++;
            v[c+N][b+N]++;
        }
        else{
            cin>>b>>c>>d;
            b--;c--;d--;
            v[b][c+N]++;
            v[b][d+N]++;
            v[c][b+N]++;
            v[c][d+N]++;
            v[d][b+N]++;
            v[d][c+N]++;
        }
    }
    //디버깅용
    v=matrixpow(v,T);
    for(int i=N;i<N*2;i++){
        cout<<v[i][N]<<'\n';
    }
}