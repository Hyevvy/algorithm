#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
using p = pair<int, int>;
using t = tuple<int, int, int>;
int N, M;
int arr[1010][1010];
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
bool visited[1010][1010][2]; //1이 부수지 않은거 0이 부순거
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
struct State {
	int r, c, crushed;
	State(int x, int y, int z) {
		r = x, c = y, crushed = z;
	}
};
int bfs() {
	int cnt = 0;
	queue<State> q;
	q.push({ 0, 0, 1 });
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cr = q.front().r;
			int cc = q.front().c;
			int crushed = q.front().crushed;
			q.pop();
			if (cr == N - 1 && cc == M - 1) return cnt + 1;
			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];
				if (!isIn(nr, nc) || visited[nr][nc][crushed]) continue;
				if (arr[nr][nc] == 1) {
					if (crushed == 0) continue;
					visited[nr][nc][0] = true;
					q.push({ nr, nc, 0 });
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
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf_s("%1d", &arr[i][j]);
		}
	}
	cout << bfs();
	return 0;
}