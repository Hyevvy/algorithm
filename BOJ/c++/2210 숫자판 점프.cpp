#include <iostream>
#include <vector>
using namespace std;
int roffset[] = { -1, 0, 0 ,1 };
int coffset[] = { 0, -1, 1, 0 };
int arr[6][6], ans;
string temp;
bool visited[1000000];
bool isIn(int r, int c) {
	return r >= 0 && r < 5 && c >= 0 && c < 5;
}

int getNum(string num) {
	int sum = 0;
	for (int i = 0; i < num.size(); i++) {
		sum += (num[i] - '0') * pow(10, 5 - i);
	}
	return sum;
}

void dfs(int cnt, int r, int c) {
	if (cnt == 6) {
		int ret = getNum(temp);
		if (!visited[ret]) {
			visited[ret] = true;
			ans++;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = r + roffset[i];
		int nc = c + coffset[i];
		if (!isIn(nr, nc)) continue;
		temp += arr[nr][nc] + '0';
		dfs(cnt + 1, nr, nc);
		temp.pop_back();
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			dfs(0, i, j);
		}
	}

	cout << ans << "\n";
	return 0;
}