#include <iostream>
using namespace std;
int n, m;
int arr[110][110];
int main() {
	cin >> n >> m;
	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		if (arr[a][b] != 0) {
			arr[a][b] = min(arr[a][b], c);
		}
		else arr[a][b] = c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (arr[i][j] == 0) arr[i][j] = 1e9;
	}

	//플로이드
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				arr[i][j] = min(arr[i][j], (arr[i][k] + arr[k][j]));
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 1e9 || i == j) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}