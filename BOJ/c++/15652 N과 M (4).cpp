#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> v;
void f(int cnt, int pos) {
	if (cnt == M) {
		for (auto curr : v) {
			cout << curr << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = pos; i <= N; i++) {
		v.push_back(i);
		f(cnt + 1, i);
		v.pop_back();
	}
}
int main() {
	cin >> N >> M;
	f(0, 1);
	return 0;
}