#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int N, M, arr[1010][1010];
bool visited[1010][1010];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
bool canPercolate = false;
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

void dfs(int r, int c) {
	visited[r][c] = true;
	if (r == N - 1) canPercolate = true;
	for (int i = 0; i < 4; i++) {
		int nr = r + roffset[i];
		int nc = c + coffset[i];
		if (visited[nr][nc] || arr[nr][nc] == 1) continue;
		if (isIn(nr, nc)) {
			dfs(nr, nc);
			visited[nr][nc] = true;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}


	for (int j = 0; j < M; j++) {
		if (arr[0][j] == 0) {
			dfs(0, j);
		}
	}

	if (canPercolate) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}