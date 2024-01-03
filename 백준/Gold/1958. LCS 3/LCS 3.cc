#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2,s3;
    cin>>s1>>s2>>s3;
    int n=s1.length(), m=s2.length(), z=s3.length();
    vector<vector<vector<int>>> v(n+1);
    for(int i=0;i<n+1;i++){
        v[i].resize(m+1);
        for(int j=0;j<m+1;j++){
            v[i][j].resize(z+1);
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            for(int k=1;k<z+1;k++){
                if(s1[i-1]==s2[j-1] && s2[j-1]==s3[k-1])
                    v[i][j][k]=v[i-1][j-1][k-1]+1;
                else
                    v[i][j][k]=max(v[i][j][k-1],max(v[i-1][j][k], v[i][j-1][k]));
            }   
        }
    }
    cout<<v[n][m][z]<<'\n';
}