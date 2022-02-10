#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, M, R;
vector<int> vc[100010];
bool visited[100010];
int visitTime[100010];
void bfs() {
	queue<int> q;
	q.push(R);
	visited[R] = true;
	visitTime[R] = 1;
	int time = 2;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		sort(vc[curr].begin(), vc[curr].end());
		for (auto c : vc[curr]) {
			if (!visited[c]) {
				visited[c] = true;
				q.push(c);
				visitTime[c] = time;
				time++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> R;
	for (int i = 0, u, v; i < M; i++) {
		cin >> u >> v;
		vc[u].push_back(v);
		vc[v].push_back(u);
	}

	bfs();
	for (int i = 1; i <= N; i++) {
		cout << visitTime[i] << "\n";
	}
	return 0;
}