#include <iostream>
#include <bitset>
using namespace std;
string A, B;
int main() {

	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == '1' && B[i] == '1') {
			cout << "1";
		}
		else cout << "0";
	}
	cout << "\n";

	for (int i = 0; i < B.size(); i++) {
		if (A[i] == '1' || B[i] == '1') {
			cout << "1";
		}
		else cout << "0";
	}
	cout << "\n";

	for (int i = 0; i < B.size(); i++) {
		if (A[i] != B[i]) {
			cout << "1";
		}
		else cout << "0";
	}
	cout << "\n";

	for (int i = 0; i < B.size(); i++) {
		cout << !(A[i] - '0');
	}
	cout << "\n";

	for (int i = 0; i < B.size(); i++) {
		cout << !(B[i] - '0');
	}
	cout << "\n";
	return 0;
}