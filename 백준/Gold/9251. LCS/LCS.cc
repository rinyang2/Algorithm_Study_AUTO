#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    int n=s1.length(), m=s2.length();
    vector<vector<int>> v(n+1);
    for(int i=0;i<n+1;i++){
        v[i].resize(m+1);
        if(i>0){
            for(int j=1;j<m+1;j++){
                if(s1[i-1]==s2[j-1])
                    v[i][j]=v[i-1][j-1]+1;
                else
                    v[i][j]=max(v[i-1][j], v[i][j-1]);
            }
        }
    }
    cout<<v[n][m];
}