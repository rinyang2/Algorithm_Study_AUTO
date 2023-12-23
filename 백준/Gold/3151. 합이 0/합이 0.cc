#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> v(N);
    for(int i=0 ;i<N;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    long long cnt = 0;
    for(int i=0;i<N-2;i++){
        for(int j = i+1;j<N-1;j++){
            auto a=equal_range(v.begin()+j+1, v.end(), -v[i]-v[j]);
            cnt+=a.second-a.first;
        }
    }
    cout<<cnt;
}