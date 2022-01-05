#include <iostream>
#include <queue>
using namespace std;
int N, M, H;
int t[110][110][110];
bool visited[110][110][110];
int roffset[] = { 0, 0, -1, 0, 0, 1 };
int coffset[] = { 0, 0, 0, -1, 1, 0 };
int hoffset[] = { 1, -1, 0, 0, 0, 0 };
struct Tomato {
	int r, c, h;
	Tomato(int x, int y, int z) {
		h = x, r = y, c = z;
	}
};
queue<Tomato> q;

bool isIn(int r, int c, int h) {
	return r >= 0 && r < N&& c >= 0 && c < M&& h >= 0 && h < H;
}
bool isFinished() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (t[i][j][k] == 0) return false;
			}
		}
	}
	return true;
}
int bfs() {
	int cnt = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {

			Tomato tf = q.front();
			q.pop();

			for (int j = 0; j < 6; j++) {
				int nr = tf.r + roffset[j];
				int nc = tf.c + coffset[j];
				int nh = tf.h + hoffset[j];
				if (!isIn(nr, nc, nh) || visited[nh][nr][nc] || t[nh][nr][nc] == -1) continue;
				if (t[nh][nr][nc] == 0) {
					q.push(Tomato(nh, nr, nc));
					t[nh][nr][nc] = 1;
					visited[nh][nr][nc] = true;
				}
			}
		}
		cnt++;
		if (isFinished()) return cnt;

	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N >> H;
	int state = 0;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> t[i][j][k];
				if (t[i][j][k] == 1) {
					q.push(Tomato(i, j, k));
					visited[i][j][k] = true;
				}
				else if (t[i][j][k] == 0) state = 1;
			}
		}
	}

	if (state == 0) cout << 0 << "\n";
	else {
		int ans = bfs();
		cout << ans << "\n";
	}


	return 0;
}