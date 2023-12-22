#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M;
    cin>>N>>M;
    int idx = 0;
    int cnt = 0;
    vector<int> v(N);
    for(int i = 0 ; i < N ; i++){
        v[i] = i+1;
    }
    for(int i = 0 ; i < M ; i++){
        int temp;
        cin>>temp;
        int index = find(v.begin(), v.end(), temp)-v.begin();
        cnt+=index*(index<v.size()-index)+(v.size()-index)*(index>=v.size()-index);
        vector<int> x;
        for(int j = index+1; j<v.size(); j++){
            x.push_back(v[j]);
        }
        for(int j =0;j<index;j++){
            x.push_back(v[j]);
        }
        v = x;
    }
    cout<<cnt;
}