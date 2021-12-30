#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
int main() {
	int n;
	string name;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name;
		mp[name]++;
	}

	for (int i = 0; i < n - 1; i++) {
		cin >> name;
		mp[name]--;
	}
	for (auto curr : mp) {
		if (curr.second != 0) cout << curr.first << "\n";
	}
	return 0;
}