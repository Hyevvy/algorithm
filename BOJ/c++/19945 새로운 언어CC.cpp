#include <iostream>
#include <string>
using namespace std;
int main() {
	int n;
	cin >> n;
	string str = "";
	if (n < 0) {
		cout << 32 << "\n";
		return 0;
	}
	if (n == 0) {
		cout << 1 << "\n";
		return 0;
	}
	for (int i = n; i > 0; i = i / 2) {
		str += i % 2 + '0';
	}
	cout << str.size();
	return 0;
}