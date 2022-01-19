#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<int> v;
int N;
bool visited[10];
void f(int cnt) {
	if (cnt == N) {

		for (auto curr : v) {
			cout << curr << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			f(cnt + 1);
			v.pop_back();
			visited[i] = false;
		}

	}

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	f(0);
	return 0;
}