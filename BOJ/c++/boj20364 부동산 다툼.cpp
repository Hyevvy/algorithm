#include <iostream>
#include <vector>
using namespace std;
int n, q;
int visited[1100000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;

	for (int i = 0, u; i < q; i++) {
		cin >> u;

		int minArea = 1e9;
		for (int j = u; j > 1; j = j / 2) {
			if (visited[j]) minArea = min(minArea, j);
		}
		if (minArea == 1e9) cout << "0\n";
		else cout << minArea << "\n";
		visited[u] = true;
	}
	return 0;
}