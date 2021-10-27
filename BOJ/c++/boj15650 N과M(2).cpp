#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> v;
void printC(int cnt, int curr) {
	if (cnt == m) {
		for (auto currC : v) {
			cout << currC << " ";
		}
		cout << "\n";
	}
	for (int i = curr; i <= n; i++) {
		//선택
		v.push_back(i);
		printC(cnt + 1, i + 1);
		//비선택
		v.pop_back();
	}

	return;
}

int main() {

	cin >> n >> m;
	printC(0, 1);
	return 0;
}