#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[100010];
long long sums[100010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		sums[i] = sums[i - 1] + arr[i];
	}
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		cout << sums[e] - sums[s - 1] << "\n";
	}

	return 0;
}