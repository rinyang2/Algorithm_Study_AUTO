#include <iostream>
#include <vector>
#include <unordered_set>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int A,B;
	cin>>A>>B;
	unordered_set<int> us;
	for(int i = 0 ; i < A+B; i++){
		int temp;
		cin>>temp;
		us.insert(temp);
	}
	cout<<A+B-(A+B-us.size())*2;
}