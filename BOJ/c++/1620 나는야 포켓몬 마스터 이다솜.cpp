#include <iostream>
#include <string>
#include <map>
using namespace std;
int N, M;
map<string, int> mp;
string strs[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	string str;
	for (int i = 1; i <= N; i++) {
		cin >> str;
		mp[str] = i;
		strs[i] = str;
	}

	for (int i = 1; i <= M; i++) {
		cin >> str;
		if (str[0] >= '0' && str[0] <= '9') {
			int n = stoi(str);
			cout << strs[n] << "\n";
		}
		else {
			cout << mp[str] << "\n";
		}
	}

	return 0;
}