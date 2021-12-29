#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int arr[26];
bool isPangram(string str) {
	for (int i = 0; i < str.size(); i++) {
		arr[str[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0) return false;
	}
	return true;
}
int main() {
	while (1) {
		string str;
		getline(cin, str);
		memset(arr, 0, sizeof(arr));
		if (str == "*") return 0;
		if (isPangram(str))cout << "Y\n";
		else cout << "N\n";
	}
	return 0;
}