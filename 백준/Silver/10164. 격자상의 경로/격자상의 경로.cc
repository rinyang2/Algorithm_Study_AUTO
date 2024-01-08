#include <iostream>
#include <vector>
#include <unordered_set>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N,M,O;
	cin>>N>>M>>O;
	vector<vector<long long>>v(50);
	v[0]={1};
	v[1]={1,1};
	for(int i = 2; i<50; i++){
		v[i].push_back(1);
		for(int j = 0;j<v[i-1].size()-1;j++){
			v[i].push_back(v[i-1][j]+v[i-1][j+1]);
		}
		v[i].push_back(1);
	}
	int y,x;
	if(O==0){
		y=N-1;
		x=M-1;
	}
	else if(O%M){
		y=O/M;
		x=O%M-1;
	}
	else{
		y=O/M-1;
		x=M-1;
	}
	cout<<v[y+x][y]*v[N+M-y-x-2][N-y-1];
}