#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int roffset[] = { -1,0,0,1 };
int coffset[] = { 0, -1,1,0 };
int N, M;
char arr[11][11];
queue<p> q;
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
void bfs() {
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int cr = q.front().first;
			int cc = q.front().second;
			int oceans = 0;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];
				if (!isIn(nr, nc)) oceans++;
				if (arr[nr][nc] == '.') oceans++;
			}
			if (oceans >= 3) {
				arr[cr][cc] = '?';
			}
		}
	}
}


int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'X') {
				q.push({ i,j });
			}
		}
	}

	bfs();

	int sr = 12, sc = 12, er = -1, ec = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'X') {
				sr = min(sr, i);
				sc = min(sc, j);
				er = max(er, i);
				ec = max(ec, j);
			}
		}
	}

	for (int i = sr; i <= er; i++) {
		for (int j = sc; j <= ec; j++) {
			if (arr[i][j] == '?') {
				cout << ".";
			}
			else cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}