#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[110][110];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) arr[i][j] = 1e9;
		}
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = min(arr[i][j], (arr[i][k] + arr[k][j]));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1e9) cout << "0 ";
			else cout << "1 ";
		}
		cout << "\n";

	}

	return 0;
}