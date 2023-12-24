#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    vector<pair<int,int>> v(31);
    v[0] = {1,0};
    v[1] = {0,1};
    for(int i = 2; i < 31; i++){
        v[i] = {v[i-1].first+v[i-2].first, v[i-1].second+v[i-2].second};
    }
    int D,K;
    cin>>D>>K;
    int a = v[D-1].first, b=v[D-1].second;
    for(int i =1;; i++){
        if((K-a*i)%b == 0){
            cout<<i<<endl;
            cout<<(K-a*i)/b<<endl;
            break;
        }
    }
}
