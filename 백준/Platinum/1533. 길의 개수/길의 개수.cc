#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MOD = 1000003;
#define endl '\n'
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
vvi matrixpow(vvi v, ll n){
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
	int N, S, E, T;
	cin>>N>>S>>E>>T;
	vvi v(N*5);
	for(int i=0;i<N*5;i++){
		v[i].resize(N*5);
	}
	for(int i = 0 ; i < N ; i++){
		string s;
		cin>>s;
		for(int j = 0 ; j < N ; j++){
			int temp=s[j]-'0';
			if(temp>0){
				v[5*i][5*j+temp-1]=1;
			}
		}
	}
	for(int i = 0; i<N*5; i++){
		for(int j=0;j<N*5;j++){
			if(i/5==j/5){
				if(i%5-j%5==1){
					v[i][j]=1;
				}
			}
		}
	}
    v=matrixpow(v,T);
	cout<<v[5*(S-1)][5*(E-1)];
}