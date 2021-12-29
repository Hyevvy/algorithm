#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>
using namespace std;
using p = pair<int, int>;
using t = tuple<int, int, int>;
int dist[200][200];
int arr[200][200];
int n;
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };
bool isIn(int r, int c) {
	return r >= 1 && r <= n && c >= 1 && c <= n;
}
void dijk(int sr, int sc, int er, int ec) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			dist[i][j] = 1e9;
	}

	priority_queue<t, vector<t>, greater<t>> pq;
	dist[sr][sc] = arr[sr][sc];
	pq.push({ arr[sr][sc], sr, sc }); //갱신된 거리, 좌표

	while (!pq.empty()) {
		int cr = get<1>(pq.top());
		int cc = get<2>(pq.top());
		if (cr == er && cc == ec) return;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nr = cr + roffset[i];
			int nc = cc + coffset[i];
			if (!isIn(nr, nc)) continue;
			if (dist[nr][nc] > arr[nr][nc] + dist[cr][cc]) {
				dist[nr][nc] = arr[nr][nc] + dist[cr][cc];
				pq.push({ dist[nr][nc], nr, nc });
			}
		}
	}
}
int main() {
	int tc = 1;
	while (1) {
		cin >> n;
		if (n == 0) return 0;
		memset(dist, 0, sizeof(dist));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}

		dijk(1, 1, n, n);
		cout << "Problem " << tc << ": " << dist[n][n] << "\n";
		tc++;
	}
	return 0;
}