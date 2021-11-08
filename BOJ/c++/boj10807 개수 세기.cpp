#include <iostream>
#include <map>
using namespace std;
int main() {
	int n, target;
	cin >> n;
	map<int, int> mp;
	for (int i = 0, u; i < n; i++) {
		cin >> u;
		mp[u]++;
	}
	cin >> target;
	cout << mp[target];
	return 0;
}