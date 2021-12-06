#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> v[20010];
bool visited[20010];
int maxVal = 0; 
int maxDistIdx = 0; 
int sameBarns = 0;

void getBarn() {
	int dists[20010] = { 0, };
	
	queue<int> q;
	q.push(1);

	int dist = 0;
	dists[0] = 0;

	while (!q.empty()) {
		
		int qSize = q.size();
		dist++;
		for (int i = 0; i < qSize; i++) {
			int qFront = q.front();
			q.pop();
			visited[qFront] = true;

			for (auto next : v[qFront]) {
				if (!visited[next]) {
					if (dists[next] == 0) {
						q.push(next);
						visited[next] = true;
						dists[next] = dist;
					}

				}
			}
		}
	}


	for (int i = 2; i <= N; i++) {
		maxVal = max(maxVal, dists[i]);
	}

	for (int i = 2; i <= N; i++) {
		
		if (dists[i] == maxVal) {
			if(maxDistIdx == 0)	maxDistIdx = i;
			sameBarns++;
		}
	}
}
int main() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	getBarn();
	cout << maxDistIdx << " " << maxVal << " " << sameBarns << "\n";
	return 0;
}