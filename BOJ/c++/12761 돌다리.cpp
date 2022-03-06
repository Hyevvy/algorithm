#include <iostream>
#include <queue>
using namespace std;
int A, B, N, M;
bool visited[30000010];
int offset[] = { -1, 1 };
bool isIn(int n) {
	return n >= 0 && n <= 100000;
}
int bfs() {
	queue<int> q;
	q.push(N);
	visited[N] = true;
	int cnt = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			int curr = q.front();
			q.pop();
			if (curr == M) {
				return cnt;
			}
			for (int j = 0; j < 2; j++) {
				int next = curr + offset[j];
				if (!visited[next] && isIn(next)) {
					q.push(next);
					visited[next] = true;
				}
			}

			for (int j = 0; j < 2; j++) {
				int next = curr + A * offset[j];
				if (!visited[next] && isIn(next)) {
					q.push(next);
					visited[next] = true;
				}
			}

			for (int j = 0; j < 2; j++) {
				int next = curr + B * offset[j];
				if (!visited[next] && isIn(next)) {
					q.push(next);
					visited[next] = true;
				}
			}

			int next = curr * A;
			if (!visited[next] && isIn(next)) {
				q.push(next);
				visited[next] = true;
			}

			next = curr * B;
			if (!visited[next] && isIn(next)) {
				q.push(next);
				visited[next] = true;
			}
		}

		cnt++;
	}
	return -1;
}
int main() {
	cin >> A >> B >> N >> M;
	cout << bfs() << "\n";
	return 0;
}