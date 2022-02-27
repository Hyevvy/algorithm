#include <iostream>
using namespace std;
int N;
string str, ret;
int arr[] = { 3,2,1,2,3,3,3,3,1,1,3,1,3,3,1,2,2,2,1,2,1,1,2,2,2,1 };
void change() {
	for (int i = 0; i < str.size(); i++) {
		ret += arr[str[i] - 'A'] + '0';
	}
}
int main() {
	cin >> str;
	change();
	while (ret.size() != 1) {
		string tmp;
		int i, j;
		for (i = 0, j = 1; j < ret.size(); i = i + 2, j = j + 2) {
			int num = (ret[i] - '0' + ret[j] - '0');
			tmp += (num % 10) + '0';
		}
		if (ret.size() % 2 != 0) {
			tmp += ret[ret.size() - 1];
		}
		ret = tmp;
	}
	if ((ret[0] - '0') % 2 == 0) {
		cout << "You're the winner?\n";
	}
	else cout << "I'm a winner!\n";

	return 0;
}