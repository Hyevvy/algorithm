#include <iostream>
#include <vector>
using namespace std;
bool visited[1001];
int N, ret;
vector<int> v;
int arr[] = { 1, 5, 10, 50 };
void f(int cnt, int idx) {
	if (cnt == N) {
		int sum = 0;
		for (int n : v) {
			sum += n;
		}
		if (!visited[sum]) {
			visited[sum] = true;
			ret++;
		}
		return;
	}
	for (int i = idx; i < 4; i++) {
		v.push_back(arr[i]);
		f(cnt + 1, i);
		v.pop_back();
	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	f(0, 0);
	cout << ret << "\n";
	return 0;
}