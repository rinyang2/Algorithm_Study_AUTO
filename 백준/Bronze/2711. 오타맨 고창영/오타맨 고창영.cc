#include<iostream>
#include<string>
#define endl '\n'
using namespace std;
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		string s;
		cin>>n>>s;
		for(int i=0;i<s.length();i++){
			if(i!=n-1)
			cout<<s[i];
		}
		cout<<endl;
	}
}