#include <iostream>
using namespace std;
int N;
void print(int n) {
	if (n == 0) return;
	for (int j = 0; j < 4 * n; j++) {
		for (int i = 0; i < n; i++) {
			cout << "@";
		}
		cout << "\n";
	}
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 5 * n; i++) {
			cout << "@";
		}
		cout << "\n";
	}
}
int main() {
	cin >> N;
	print(N);
	return 0;
}