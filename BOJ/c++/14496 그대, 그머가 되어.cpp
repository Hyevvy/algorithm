#include < iostream >
#include < algorithm >
#include < cstring >
#include < vector >
#include < queue >
using namespace std;
int N, M, a, b;
vector < int > V[1010];
bool visited[1010];
int minVal = 1e9;

void bfs() {
	queue < int > q;
	q.push(a);
	visited[a] = true;
	int cnt = 1;

	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curr = q.front();
			q.pop();
			for (int next : V[curr]) {
				if (!visited[next]) {
					if (next == b) {
						minVal = min(minVal, cnt);
					}
					q.push(next);
					visited[next] = true;
				}
			}
		}
		cnt++;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> b >> N >> M;
	for (int i = 0, u, v; i < M; i++) {
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	bfs();
	if (a == b) cout << 0;
	else {
		if (minVal == 1e9) cout << -1;
		else cout << minVal;
	}

	return 0;
}