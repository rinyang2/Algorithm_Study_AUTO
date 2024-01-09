#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
#define ll long long
#define vvi vector<vector<ll>>

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
	int T;
    cin>>T;
    //인접행렬을 담기 위한 벡터
    vvi v(8);
    v[0]={0,1,0,1,0,0,0,0};
	v[1]={1,0,1,0,0,0,0,0};
	v[2]={0,1,0,1,1,1,0,0};
	v[3]={1,0,1,0,1,0,0,0};
	v[4]={0,0,1,1,0,1,1,0};
	v[5]={0,0,1,0,1,0,1,1};
	v[6]={0,0,0,0,1,1,0,1};
	v[7]={0,0,0,0,0,1,1,0};
    v=matrixpow(v,T);
	int ans=0;
   cout<<v[7][7];
}