#include <iostream>
#include <queue>
using namespace std;
using t = tuple<int, int, int>;
int N, M, T;
int arr[110][110];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
int cnt = 0;
bool visited[110][110][2]; // 0:그람이 없음, 1 : 그람이 있음
struct Prince {
	int r, c, haveG;
	Prince(int x, int y, int z) {
		r = x, c = y, haveG = z;
	}
};
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
int bfs() {
	queue<Prince> q;
	q.push({ 0,0,0 });
	visited[0][0][0] = true;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cr = q.front().r;
			int cc = q.front().c;
			int haveG = q.front().haveG;
			q.pop();

			if (cr == N - 1 && cc == M - 1) return cnt;
			if (cnt > T) return -1;
			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];
				if (!isIn(nr, nc) || visited[nr][nc][haveG]) continue;
				if (haveG == 1) {
					//어떠한 벽이든 부술 수 있음
					q.push({ nr, nc, haveG });
					visited[nr][nc][haveG] = true;
				}
				else {
					if (arr[nr][nc] == 2) {
						q.push({ nr, nc, 1 });
						visited[nr][nc][1] = true;
					}
					else {
						if (arr[nr][nc] == 1) continue;
						q.push({ nr, nc, haveG });
						visited[nr][nc][haveG] = true;
					}

				}
			}

		}
		cnt++;
	}
	return -1;
}
int main() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int ans = bfs();
	if (ans == -1) cout << "Fail\n";
	else cout << ans << "\n";
	return 0;
}