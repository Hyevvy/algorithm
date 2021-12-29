#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
using p = pair<int, int>;
int N, D, target;
int tc;
vector<p> adj[100010];
int dist[100010];
void dijk() {
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e9;
	}
	dist[target] = 0;
	priority_queue<p, vector<p>, greater<p>> pq;
	pq.push({ 0, target });
	while (!pq.empty()) {
		int currV = pq.top().second;
		pq.pop();
		for (auto next : adj[currV]) {
			int nextV = next.first;
			int nextW = next.second;
			if (dist[nextV] > dist[currV] + nextW) {
				dist[nextV] = dist[currV] + nextW;
				pq.push({ dist[nextV], nextV });
			}
		}
	}

}
int main() {
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> N >> D >> target;
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}
		for (int j = 1, from, to, w; j <= D; j++) {
			cin >> from >> to >> w;
			adj[to].push_back({ from, w });
		}
		dijk();


		int cnt = 0; //馬膩脹 pc曖 熱
		int maxTime = -1e9; //馬膩 衛除
		for (int i = 1; i <= N; i++) {
			if (dist[i] != 1e9) {
				cnt++;
				maxTime = max({ maxTime , dist[i] });
			}
		}
		//cout << "***************\n";
		if (maxTime == 1e9) maxTime = 1;
		cout << cnt << " " << maxTime << "\n";
	}


	return 0;
}