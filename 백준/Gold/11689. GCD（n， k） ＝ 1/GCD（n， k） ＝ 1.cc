#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'

unordered_map<ll,ll> factorize(ll n){
    unordered_map<ll,ll> temp;
    ll div = 2;
    while(div*div<=n){
        if(n%div)
            div++;
        else{
            temp[div]++;
            n/=div;
        }
    }
    if(n>1){
        temp[n]++;
    }
    return temp;
}

ll euler_phi(ll n){
    unordered_map<ll,ll> temp= factorize(n);
    ll x=1;
    for(auto a: temp){
        x*=pow(a.first,a.second-1)*(a.first-1);
    }
    return x;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll N;
    cin>>N;
    cout<<euler_phi(N);
}