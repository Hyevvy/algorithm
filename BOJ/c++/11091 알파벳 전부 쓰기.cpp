#include <iostream>
#include <string>
using namespace std;
int arr[26];
int tc;
bool isPangram(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			//cout << str[i] << " " << str[i] - 'A' << "\n";
			arr[str[i] - 'A']++;
		}
	}
	int state = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == 0)  state = 1;
		//cout << arr[i] << " ";
	}
	if (state == 1) return false;
	return true;
}
string toUpper(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') continue;
		str[i] = str[i] - ('a' - 'A');
	}
	return str;
}
int main() {
	cin >> tc;
	cin.ignore();
	for (int i = 0; i < tc; i++) {
		memset(arr, 0, sizeof(arr));
		string str;

		getline(cin, str);
		string upperStr = toUpper(str);

		if (isPangram(upperStr) == false) {
			cout << "missing ";
			for (int j = 0; j < 26; j++) {
				if (arr[j] == 0) cout << char(j + 'a');
			}
			cout << "\n";
		}
		else cout << "pangram\n";
	}

	return 0;
}