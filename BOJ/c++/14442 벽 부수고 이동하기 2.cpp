#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using t = tuple<int, int, int>;
int N, M, K;
int arr[1010][1010];
bool visited[1010][1010][10];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
struct State {
	int r, c, crushed;
	State(int x, int y, int z) {
		r = x;
		c = y;
		crushed = z;
	}
};
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}

int bfs() {
	queue<State> q;
	q.push({ 0, 0, 0 });
	int cnt = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			int cr = q.front().r;
			int cc = q.front().c;
			int crushed = q.front().crushed;
			q.pop();
			if (cr == N - 1 && cc == M - 1) return cnt + 1;
			for (int i = 0; i < 4; i++) {
				int nr = cr + roffset[i];
				int nc = cc + coffset[i];
				if (!isIn(nr, nc) || visited[nr][nc][crushed]) continue;
				if (arr[nr][nc] == 1) {
					//벽인 경우
					if (crushed < K) {
						visited[nr][nc][crushed + 1] = true;
						q.push({ nr, nc, crushed + 1 });
					}
				}
				else {
					visited[nr][nc][crushed] = true;
					q.push({ nr, nc, crushed });
				}
			}
		}
		cnt++;
	}
	return -1;
}
int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			scanf_s("%1d", &arr[i][j]);
	}
	cout << bfs();
	return 0;
}