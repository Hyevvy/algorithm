#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	//연속해서 다른 것들의 경우를 저장해둔다.
	int zero = 0;
	int one = 0;
	int sSize = s.size();
	int conZero = 0;
	int conOne = 0;
	for (int i = 0; i < sSize; i++) {
		if (s[i] == '0') {
			if (conOne > 0) one++;
			conZero++;
			conOne = 0;
		}
		else if (s[i] == '1') {
			if (conZero > 0) zero++;
			conOne++;
			conZero = 0;
		}
	}
	if (conZero != 0) zero++;
	else if (conOne != 0) one++;
	//cout << zero << " " << one << "\n";
	if (zero == 0 || one == 0) cout << "0\n";
	else cout << min(zero, one) << "\n";
	return 0;
}