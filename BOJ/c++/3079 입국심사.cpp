#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long N, M, tmp;
vector<int> v;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());

	long long left = 1, right = v.back() * M;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;//시간안에 통과한 사람 수
		for (int i = 0; i < v.size(); i++) {
			cnt += (mid / v[i]);

		}
		if (cnt >= M) {
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << left << "\n";
	return 0;
}