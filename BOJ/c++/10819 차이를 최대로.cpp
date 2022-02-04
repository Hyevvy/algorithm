#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, arr[10], maxVal = -1e9;
vector<int> v;
bool visited[10];
int getNum() {
	int ret = 0;
	for (int i = 0; i < v.size() - 1; i++) {
		ret += abs(v[i] - v[i + 1]);
	}
	return ret;
}
void getPerm(int cnt) {
	if (cnt == N) {
		maxVal = max(maxVal, getNum());
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(arr[i]);
			getPerm(cnt + 1);
			visited[i] = false;
			v.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	getPerm(0);
	cout << maxVal << "\n";
	return 0;
}