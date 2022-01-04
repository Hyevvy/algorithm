#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int N;
vector<string> v;
int getSum(string str) {
	int sum = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			sum += str[i] - '0';
		}
	}
	return sum;
}
bool cmp(string a, string b) {
	if (a.size() == b.size()) {
		if (getSum(a) != getSum(b)) return getSum(a) < getSum(b);
		else return a < b;
	}
	else return a.size() < b.size();
}
int main() {
	cin >> N;
	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);
	for (auto curr : v) {
		cout << curr << "\n";
	}
	return 0;
}