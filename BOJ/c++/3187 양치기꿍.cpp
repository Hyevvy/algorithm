#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using p = pair<int, int>;
char arr[255][255];
bool visited[255][255];
int roffset[] = { -1,0,0,1 };
int coffset[] = { 0,-1,1,0 };
int R, C;
int K, V; //¾ç , ´Á´ë
bool isIn(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}
void bfs(int r, int c) {
	queue<p> q;
	q.push({ r, c });
	visited[r][c] = true;
	int k = 0, v = 0;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + roffset[i];
			int nc = cc + coffset[i];
			if (!isIn(nr, nc) || visited[nr][nc]) continue;
			if (arr[nr][nc] != '#') {
				q.push({ nr, nc });
				visited[nr][nc] = true;
				if (arr[nr][nc] == 'v') v++;
				else if (arr[nr][nc] == 'k') k++;
			}
		}
	}
	if (k > v) V = V - v;
	else K = K - k;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'v') V++;
			else if (arr[i][j] == 'k') K++;
		}
	}


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && arr[i][j] == '#') {
				bfs(i, j);
			}
		}
	}

	cout << K << " " << V << "\n";
	return 0;
}