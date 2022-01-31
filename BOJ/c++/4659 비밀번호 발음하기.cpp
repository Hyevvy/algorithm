#include <iostream>
using namespace std;
char vowels[] = { 'a', 'e', 'i' , 'o', 'u' };
bool isVowel(char c) {
	for (int i = 0; i < 5; i++) {
		if (c == vowels[i]) return true;
	}
	return false;
}

bool isAcceptable(string s) {

	char prev = s[0];
	bool hasVowel = false;
	int currVowel = 0;
	int currConstant = 0;
	if (isVowel(prev)) {
		hasVowel = true;
		currVowel++;
		currConstant = 0;
	}
	else {
		currVowel = 0;
		currConstant++;
	}

	for (int i = 1; i < s.size(); i++) {

		if (s[i] == prev) {
			if (s[i] != 'e' && s[i] != 'o') return false;
		}
		if (isVowel(s[i])) {
			currVowel++;
			currConstant = 0;
			hasVowel = true;
		}
		else {
			currVowel = 0;
			currConstant++;
		}
		if (currVowel >= 3 || currConstant >= 3) return false;
		prev = s[i];
	}
	if (!hasVowel) return false;
	return true;
}
int main() {
	string inputStr;
	while (1) {
		cin >> inputStr;
		if (inputStr == "end") break;
		if (isAcceptable(inputStr)) {
			cout << "<" << inputStr << "> is acceptable.\n";
		}
		else {
			cout << "<" << inputStr << "> is not acceptable.\n";
		}
	}
	return 0;
}