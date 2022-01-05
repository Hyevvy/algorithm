#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using p = pair<int, int>;
int N, M;
char maps[52][52];
char temp[52][52];
char temp2[52][52];
vector<int> rects;
int getRepaintaRect(int sr, int sc, int er, int ec) {
	int cnt = 0, cnt2 = 0;
	for (int i = sr; i < er; i++) {
		for (int j = sc; j < ec; j++) {
			if (maps[i][j] != temp[i][j]) cnt++;
		}
	}

	for (int i = sr; i < er; i++) {
		for (int j = sc; j < ec; j++) {
			if (maps[i][j] != temp2[i][j]) cnt2++;
		}
	}

	return min(cnt, cnt2);
}
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			cin >> maps[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i % 2 != 0) {
				if (j % 2 != 0)temp[i][j] = 'W';
				else temp[i][j] = 'B';
			}
			else {
				if (j % 2 != 0)temp[i][j] = 'B';
				else temp[i][j] = 'W';
			}
		}
	}


	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i % 2 != 0) {
				if (j % 2 != 0)temp2[i][j] = 'B';
				else temp2[i][j] = 'W';
			}
			else {
				if (j % 2 != 0)temp2[i][j] = 'W';
				else temp2[i][j] = 'B';
			}
		}
	}

	//일단 시작점을 잡는다

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (N - i + 1 >= 8 && M - j + 1 >= 8) {
				rects.push_back(getRepaintaRect(i, j, i + 8, j + 8));
			}
		}
	}

	sort(rects.begin(), rects.end());
	cout << rects[0];
	return 0;
}