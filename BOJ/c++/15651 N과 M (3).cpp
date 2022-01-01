#include <iostream>
#include <vector>
using namespace std;
int N, M;
bool visited[10];
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
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			visited[i] = false;
			f(cnt + 1, pos);
			v.pop_back();

		}

	}
}
int main() {
	cin >> N >> M;
	f(0, 1);
	return 0;
}