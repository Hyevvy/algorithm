#include <iostream>
using namespace std;
int N, K;
int w[110];
int v[110];
int dp[110][100010];
int f(int pos, int W) {
	if (dp[pos][W] > 0) return dp[pos][W];
	if (pos == N) return 0;
	int n1 = 0;
	if (W + w[pos] <= K) n1 = v[pos] + f(pos + 1, W + w[pos]);
	int n2 = f(pos + 1, W);
	return dp[pos][W] = max(n1, n2);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	cout << f(0, 0);
	return 0;
}