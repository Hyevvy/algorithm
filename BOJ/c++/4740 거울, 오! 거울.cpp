#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	while (1) {
		getline(cin, a);
		//cin >> a;
		if (a == "***") break;
		for (int i = a.size() - 1; i >= 0; i--) {
			cout << a[i];
		}
		cout << "\n";
	}
	return 0;
}