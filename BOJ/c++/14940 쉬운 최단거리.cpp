#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int N, M, arr[1010][1010];
int dist[1010][1010];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
void bfs(int sr, int sc) {
	queue<p> q;
	q.push({ sr, sc });
	dist[sr][sc] = 0;
	while (!q.empty()) {
		int cr = q.front().first;
		int cc = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = roffset[i] + cr;
			int nc = coffset[i] + cc;
			if (!isIn(nr, nc) || dist[nr][nc] || arr[nr][nc] == 0) continue;
			if (nr == sr && nc == sc) continue;
			q.push({ nr,nc });
			dist[nr][nc] = dist[cr][cc] + 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	p start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				start = { i, j };
			}
		}
	}

	bfs(start.first, start.second);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1 && dist[i][j] == 0) cout << "-1 ";
			else cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}