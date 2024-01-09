#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define endl '\n'
#define vvi vector<vector<ll>>

const ll MOD = 1000000007;

vvi matrixmul(vvi &v1, vvi &v2){
    ll size = v1.size();
    vvi res(size);
    for(ll i = 0 ; i < size; i++){
        res[i].resize(size);
    }
    for(ll i = 0; i<size; i++){
        for(ll j = 0 ; j < size; j++){
            for(ll k = 0 ; k<size; k++){
                res[i][j]+=(v1[i][k]*v2[k][j])%MOD;
            }
            res[i][j]%=MOD;
        }
    }
    return res;
}
vvi matrixpow(vvi v, ll n){
    ll size=v.size();
    //단위행렬
    vvi res(size);
    for(ll i=0; i<size; i++){
        res[i].resize(size);
        res[i][i]=1;
    }
    while(n){
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
	ll N;
	vvi v={{4,-1},{1,0}};
	cin>>N;
	if(N%2){
		cout<<0;
	}
	else{
		v=matrixpow(v,N/2);
		ll temp=v[0][0]+v[0][1];
		temp%=MOD;
		if(temp<0){
			temp = MOD+temp;
		}
		cout<<temp;
	}
    
}