#include <iostream>
using namespace std;
int N, M;
int arr[100010];
bool f(int mid) {
	int cnt = 1;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		if (arr[i] > mid) return false;
		sum += arr[i];
		if (sum > mid) {
			sum = arr[i];
			cnt++;
		}
	}
	return M >= cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	int sum = 0, low = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		low = max(low, arr[i]);
	}
	int high = sum;
	int ret = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (f(mid)) {
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << low << "\n";
	return 0;
}