#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
using p = pair<int, int>;
int N, M;
int arr[101][101];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

bool finish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 1) return false;
		}
	}
	return true;
}
int bfs() {
	queue<p> q;
	q.push({ 0, 0 });
	bool visited[101][101]{ false, };
	int cheese = 0;
	while (!q.empty()) {

		visited[0][0] = true;
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cr = q.front().first;
			int cc = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];
				if (!isIn(nr, nc) || visited[nr][nc]) continue;
				if (arr[cr][cc] == 0 && arr[nr][nc] == 1) {
					visited[nr][nc] = true;
					arr[nr][nc] = 0;
					cheese++;
				}
				else if (arr[nr][nc] == 0) {
					visited[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}

	return cheese;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	int ret = 0;
	while (!finish()) {
		ret = bfs();
		cnt++;
	}
	cout << cnt << "\n";
	cout << ret << "\n";
	return 0;
}