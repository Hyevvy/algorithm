#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using p = pair<int, int>;
int n;
int roffset[] = { -1,0, 0, 1, 0 };
int coffset[] = { 0, 0,-1, 0, 1 };
int costs[210][210];
bool used[210][210];
int retCost = 1e9;
vector<p> v;
int getCost(int i, int j) {
	//씨앗을 심은 곳을 기준으로 상하좌우,본인 
	//총 5군데의 씨앗값을 더해서 리턴해주는 함수
	int cost = 0;
	p curr = { i, j };
	for (int i = 0; i < 5; i++) {
		int nr = curr.first + roffset[i];
		int nc = curr.second + coffset[i];
		cost += costs[nr][nc];
	}
	return cost;
}
void visitRC(int r, int c) {
	for (int i = 0; i < 5; i++) {
		int nr = roffset[i] + r;
		int nc = coffset[i] + c;
		used[nr][nc] = true;
	}
}

void notVisitRC(int r, int c) {
	for (int i = 0; i < 5; i++) {
		int nr = roffset[i] + r;
		int nc = coffset[i] + c;
		used[nr][nc] = false;
	}
}
bool canPlant(int r, int c) {
	for (int i = 0; i < 5; i++) {
		int nr = roffset[i] + r;
		int nc = coffset[i] + c;
		if (used[nr][nc]) return false;
	}
	return true;
}
void getC(int prevR, int prevC, int cnt) {
	if (cnt == 3) {
		//baseCase
		int cost = 0;
		for (auto curr : v) {
			cost += getCost(curr.first, curr.second);
		}
		retCost = min(cost, retCost);
		return;
	}
	for (int i = prevR; i < n; i++) {
		for (int j = 2; j < n; j++) {
			if (!canPlant(i, j)) continue;
			v.push_back({ i,j });
			cnt++;
			visitRC(i, j);

			getC(i, j, cnt);
			v.pop_back();
			cnt--;
			notVisitRC(i, j);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> costs[i][j];
		}
	}

	getC(2, 2, 0);

	cout << retCost << "\n";
	return 0;
}