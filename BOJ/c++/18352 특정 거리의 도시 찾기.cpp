#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K, X;
vector<int> v[300010];
void printNodes(int start, int dist) {
	int dists[300010]{ -1, };
	queue<int> q;
	q.push(start);
	dists[start] = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curr = q.front();
			q.pop();
			for (int next : v[curr]) {
				if (dists[next] != 0 || next == start) continue;
				q.push({ next });
				dists[next] = dists[curr] + 1;
			}
		}
	}
	vector<int> nodes;
	for (int i = 1; i <= N; i++) {
		if (dists[i] == dist) {
			nodes.push_back(i);
		}
	}

	if (nodes.size() == 0) {
		cout << "-1\n";
		return;
	}
	else {
		sort(nodes.begin(), nodes.end());

		for (int node : nodes) {
			cout << node << "\n";
		}
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> K >> X;
	for (int i = 1, x, y; i <= M; i++) {
		cin >> x >> y;
		v[x].push_back(y);
	}

	printNodes(X, K);
	return 0;
}