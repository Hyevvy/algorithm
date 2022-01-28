#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int N, B, C;
long long tmp;
vector<long long> v;

int main() {
	cin >> N;
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}
	cin >> B >> C;
	for (auto curr : v) {
		if (curr < B) {
			ret++;
			continue;
		}
		ret++;
		curr -= B;

		ret += curr / C;
		if (curr % C != 0) {
			ret++;
		}
	}
	cout << ret << "\n";
	return 0;
}