#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, R;
bool visited[100001];
vector<int> V[100001];
vector<int> ret;
int order[100001];
int cnt = 1;
void dfs(int v) {
	visited[v] = true;
	order[v] = cnt++;
	sort(V[v].begin(), V[v].end());
	for (auto n : V[v]) {
		if (!visited[n]) {
			dfs(n);
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

	dfs(R);

	for (int i = 1; i <= N; i++) {
		cout << order[i] << "\n";
	}

	return 0;
}