#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using p = pair<int, int>;
int N, M;
int maxVal = -1e9;
int arr[10][10];
int arr2[10][10];
int roffset[] = { -1,0,0,1 };
int coffset[] = { 0,-1,1,0 };
vector<int> ret;
vector<p> emptySpace;
vector<p> emptyToWall;
vector<p> virusesV;
bool isIn(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
int bfs(int arr[10][10]) {
	queue<p> viruses;
	bool visited[10][10]{};
	for (auto curr : virusesV) {
		viruses.push(curr);
		visited[curr.first][curr.second] = true;
	}

	for (auto curr : emptyToWall) {
		arr[curr.first][curr.second] = 1;
	}

	while (!viruses.empty()) {
		int qSize = viruses.size();
		for (int i = 0; i < qSize; i++) {
			int cr = viruses.front().first;
			int cc = viruses.front().second;
			viruses.pop();
			for (int j = 0; j < 4; j++) {
				int nr = cr + roffset[j];
				int nc = cc + coffset[j];
				if (!isIn(nr, nc) || visited[nr][nc] || arr[nr][nc] == 1) continue;
				visited[nr][nc] = true;
				viruses.push({ nr, nc });
				arr[nr][nc] = 2;
			}
		}
	}
	int emptySpace = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (arr[i][j] == 0) emptySpace++;
	}
	return emptySpace;

}
void arrCpy(int arr2[10][10], int arr[10][10]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			arr2[i][j] = arr[i][j];
		}
	}
}
void buildWalls(int cnt, int pos) {
	if (cnt == 3) {
		arrCpy(arr2, arr);
		int ans = bfs(arr2);
		if (ans > maxVal) { maxVal = ans; }

		return;
	}
	for (int i = pos; i < emptySpace.size(); i++) {
		emptyToWall.push_back(emptySpace[i]);
		buildWalls(cnt + 1, i + 1);
		emptyToWall.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				emptySpace.push_back({ i, j });
			}
			if (arr[i][j] == 2) virusesV.push_back({ i, j });
		}
	}
	buildWalls(0, 0);

	cout << maxVal << "\n";
	return 0;
}