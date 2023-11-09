#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
using namespace std;

int n, m;
unordered_map<string, bool> arr;

void init()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string key;
		cin >> key;
		arr.insert({ key, false });
	}
}

void run()
{
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		int st = 0, en = str.find(",");
		if (en != -1) {
			string temp;
			while (true) {
				temp = str.substr(st, en - st);
				if (arr.find(temp) != arr.end() && !arr[temp]) {
					arr[temp] = true;
					cnt++;
				}
				if (en == str.size()) break;
				st = en + 1;
				en = str.find(',', st);
				if (en == -1)
					en = str.size();
			}
		}
		else {
			if (arr.find(str) != arr.end() && !arr[str]) {
				arr[str] = true; cnt++;
			}

		}
		cout << n - cnt << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	run();
	return 0;
}