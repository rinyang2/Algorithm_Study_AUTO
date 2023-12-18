#include <iostream>
#include <string>
#include<vector>
using namespace std;

bool isvowel(char c) {
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

bool isvalid(string s) {
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (isvowel(s[i])) {
			flag = true;
			break;
		}
	}
	for (int i = 0; i < s.length() - 2; i++) {
		if (s.length() < 3)
			break;
		if (isvowel(s[i]) == isvowel(s[i + 1]) and isvowel(s[i + 1]) == isvowel(s[i + 2]))
			return false;
	}
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1] and (s[i] != 'e' and s[i] != 'o'))
			return false;
	}
	return flag;
}

int main() {
	while (true) {
		string s;
		cin >> s;
		if (s == "end")
			break;
		cout << "<" << s << "> is ";
		if (!isvalid(s))
			cout << "not ";
		cout << "acceptable." << endl;
	}
}