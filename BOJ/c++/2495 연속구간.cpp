#include <iostream>
using namespace std;
string str;
int main() {
	for (int k = 0; k < 3; k++) {
		cin >> str;
		char prev = str[0];
		int curr = 1;
		int ret = 0;
		for (int i = 1; i < str.size(); i++) {
			if (prev == str[i]) {
				curr++;
			}
			else {
				ret = max(ret, curr);
				prev = str[i];
				curr = 1;
			}

		}
		cout << max(ret, curr) << "\n";
	}
	return 0;
}