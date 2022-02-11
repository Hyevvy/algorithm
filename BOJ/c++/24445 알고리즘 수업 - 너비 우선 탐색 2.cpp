#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, R;
vector<int> V[100010];
bool visited[100010];
int nodes[100010];
void bfs() {
	queue<int> q;
	q.push(R);
	visited[R] = true;
	nodes[R] = 1;
	int cnt = 2;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		sort(V[curr].begin(), V[curr].end());
		reverse(V[curr].begin(), V[curr].end());
		for (auto next : V[curr]) {
			if (!visited[next]) {
				q.push(next);
				nodes[next] = cnt;
				visited[next] = true;
				cnt++;
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
		V[u].push_back(v);
		V[v].push_back(u);
	}
	bfs();
	for (int i = 1; i <= N; i++) {
		cout << nodes[i] << "\n";
	}
	return 0;
}