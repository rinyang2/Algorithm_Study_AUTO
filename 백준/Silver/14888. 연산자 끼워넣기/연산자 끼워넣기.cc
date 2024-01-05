#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

string path="";
string key="1234";
int MAX=-1000000001;
int MIN=1000000001;
void comb(vector<int>&arr, int level, int max_depth, vector<int>&v){
    if(level==max_depth){
        //cout<<path<<'\n';
        int temp=v[0];
        for(int i=1;i<v.size();i++){
            if(path[i-1]=='1')
                temp+=v[i];
            else if(path[i-1]=='2')
                temp-=v[i];
            else if(path[i-1]=='3')
                temp*=v[i];
            else if(path[i-1]=='4')
                temp/=v[i];
        }
        //cout<<temp<<'\n';
        MAX=max(MAX, temp);
        MIN=min(MIN, temp);
        return;
    }
    for(int i = 0 ; i < 4 ; i++){
        if(arr[i]){
            arr[i]--;
            path+=key[i];
            comb(arr, level+1, max_depth,v);
            arr[i]++;
            path.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
	int N;cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    vector<int> arr(4);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    arr={a,b,c,d};
    comb(arr, 0, N-1,v);
    cout<<MAX<<'\n'<<MIN;
}