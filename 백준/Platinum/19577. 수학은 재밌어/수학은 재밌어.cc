#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long
#define endl '\n'

unordered_map<int,int> factorize(int n){
    unordered_map<int,int> temp;
    int div = 2;
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
vector<int> divisor(int n){
    vector<int> temp;
    int div=2;
    while(div*div<=n){
        if(n%div==0){
            temp.push_back(div);
            temp.push_back(n/div);
        }
        div++;
    }
    if(temp.size()==0){
        temp.push_back(n);
    }
    return temp;
}
int euler_phi(int n){
    unordered_map<int,int> temp= factorize(n);
    int x=1;
    for(auto a: temp){
        x*=pow(a.first,a.second-1)*(a.first-1);
    }
    return x;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    int N; 
    cin>>N;
	vector<int> v=divisor(N);
    sort(v.begin(), v.end());
    int t = -1;
    for(auto a: v){
        int temp = euler_phi(a);
        if(temp*a==N){
            t=a;
            break;
        }
    }
    cout<<t;
}