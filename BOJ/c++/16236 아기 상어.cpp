#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
using p = pair<int, int>;
int N, fish;
int arr[24][24];
int roffset[] = { -1,0,0,1 };
int coffset[] = { 0,-1,1,0 };
int dists[24][24];
struct bshark {
	int r, c, size;
	bshark(int x, int y, int z) {
		r = x; c = y; size = z;
	}
};
struct tfish {
	int r, c, cnt;
	tfish(int x, int y, int z) {
		r = x; c = y; cnt = z;
	}
};

vector<tfish> v;
bool isIn(int r, int c) {
	return(r >= 0 && r < N&& c >= 0 && c < N);
}

bool cmp(tfish a, tfish b) {
	if (a.cnt == b.cnt) {
		if (a.r == b.r) {
			return a.c < b.c;
		}
		return a.r < b.r;
	}
	return a.cnt < b.cnt;
}
void bfs(bshark t) {
	queue<bshark> q;
	q.push(t);

	int cnt = 0;
	bool visited[24][24]{ 0, };
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cr = q.front().r;
			int cc = q.front().c;
			int cSize = q.front().size;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];

				if (!isIn(nr, nc)) continue;
				if (visited[nr][nc]) continue;
				if (arr[nr][nc] == 0) {
					q.push({ nr, nc , cSize });
					visited[nr][nc] = true;
				}
				else if (arr[nr][nc] == 9) {
					q.push({ nr, nc, cSize });
					visited[nr][nc] = true;
				}
				else {
					if (arr[nr][nc] > cSize) continue;
					if (arr[nr][nc] == cSize) {
						q.push({ nr, nc, cSize });
						visited[nr][nc] = true;
					}
					if (arr[nr][nc] < cSize) {
						q.push({ nr, nc, cSize });
						v.push_back({ nr, nc, cnt });
						visited[nr][nc] = true;
					}
				}

			}
		}
		cnt++;
	}

}

int main() {
	cin >> N;
	bshark target = { 0,0,0 };
	int eatenFish = 0;
	int currSize = 2;
	int dist = 1;
	int times = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				target = { i,j,2 };
			}
			else if (arr[i][j] != 0) fish++;
		}
	}


	while (1) {
		if (target.r == -1 && target.c == -1) {
			break;
		}
		bfs(target);

		if (!v.empty()) {
			sort(v.begin(), v.end(), cmp);
			eatenFish++;
			if (eatenFish == currSize) {
				currSize++;
				eatenFish = 0;
			}
			dists[v[0].r][v[0].c] = dist;
			dist++;

			arr[v[0].r][v[0].c] = 0;
			fish--;

			target = { v[0].r, v[0].c, currSize };
			times += v[0].cnt + 1;
		}
		else {
			target.r = -1;
			target.c = -1;
		}

		v.clear();
	}

	cout << times << "\n";
	return 0;
}