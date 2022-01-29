#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int N, arr[200010];
int C;
bool can(int dist) {
	int left = arr[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (arr[i] - left >= dist) {
			cnt++;
			left = arr[i];
		}
	}
	return cnt >= C;
}
int binSearch(int left, int right) {
	int ans = 0;
	while (left + 1 < right) {
		int mid = (left + right) / 2;
		ans = can(mid);
		if (ans) {
			left = mid;
		}
		else right = mid;
	}
	return left;
}

int sorted[1000010];
void merge(int start, int mid, int end) {
	int i, j, k;
	i = start; j = mid + 1; k = start;
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j])
			sorted[k++] = arr[i++];
		else sorted[k++] = arr[j++];
	}

	if (i > mid) {
		while (j <= end) sorted[k++] = arr[j++];
	}
	else {
		while (i <= mid) sorted[k++] = arr[i++];
	}

	for (int i = start; i <= end; i++) {
		arr[i] = sorted[i];
	}
}

void merge_sort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		merge_sort(start, mid);
		merge_sort(mid + 1, end);
		merge(start, mid, end);
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	merge_sort(0, N - 1);
	cout << binSearch(1, arr[N - 1] + 1);

	return 0;
}