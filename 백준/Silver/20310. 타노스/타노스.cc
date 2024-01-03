#include <iostream>
#include <string>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>s;
    int zero=0, one=0;
    for(char c: s){
        if(c=='0')
            zero++;
        else
            one++;
    }
    zero/=2;
    one/=2;
    string ans="";
    for(char c: s){
        if(c=='1'){
            if(one)
                one--;
            else
                ans+='1';
        }
        else{
            if(zero){
                ans+='0';
                zero--;
            }
        }
    }
    cout<<ans;
}