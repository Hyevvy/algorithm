#include <iostream>
using namespace std;
string str;
void checkPI() {
	bool isP = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'p') {
			isP = true;
		}
		else if (isP == true && str[i] == 'i') {
			isP = false;
			str[i - 1] = '.';
			str[i] = '.';
		}
		else {
			isP = false;
		}
	}
}
void checkKa() {
	bool isK = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'k') {
			isK = true;
		}
		else if (isK == true && str[i] == 'a') {
			isK = false;
			str[i - 1] = '.';
			str[i] = '.';
		}
		else {
			isK = false;
		}
	}
}
void checkChu() {
	bool isC = false, isH = false;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'c') {
			isC = true;
		}
		else if (isC == true && str[i] == 'h') {
			isH = true;
		}
		else if (isC == true && isH == true && str[i] == 'u') {
			isC = false;
			isH = false;
			str[i - 1] = '.';
			str[i - 2] = '.';
			str[i] = '.';
		}
		else {
			isC = false;
			isH = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> str;
	checkPI();
	checkKa();
	checkChu();

	bool isPikachu = true;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '.') isPikachu = false;
	}
	if (isPikachu) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}

{/*--------------------------------------------*/}

#include <iostream>
using namespace std;
string s;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	bool c = true;
	int i = 0;
	while (s[i]) {
		if (s[i] == 'p' && s[i + 1] == 'i') i += 2;
		else if (s[i] == 'k' && s[i + 1] == 'a') i += 2;
		else if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 1] == 'u') i += 3;
		else {
			c = false;
			break;
		}
	}
	return 0;
}