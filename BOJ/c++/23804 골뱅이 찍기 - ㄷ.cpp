#include <iostream>
using namespace std;
int N;
int main() {
	cin >> N;
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N * 5; i++) {
			cout << "@";
		}
		cout << "\n";
	}
	for (int i = 0; i < 3 * N; i++) {
		for (int j = 0; j < N; j++) {
			cout << "@";
		}
		cout << "\n";
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N * 5; i++) {
			cout << "@";
		}
		cout << "\n";
	}
	return 0;
}