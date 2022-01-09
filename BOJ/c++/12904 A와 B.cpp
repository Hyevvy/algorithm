#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string S;
string T;
bool isPossible;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T >> S;
	while (!S.empty()) {
		if (S == T) isPossible = true;
		if (S[S.size() - 1] == 'A') S.pop_back();
		else {
			S.pop_back();
			reverse(S.begin(), S.end());
		}
	}
	if (isPossible) cout << "1\n";
	else cout << "0\n";
	return 0;
}