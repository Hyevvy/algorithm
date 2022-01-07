#include <iostream>
#include <vector>
#include <string>
using namespace std;
string N;
long long ret = 0;
vector<string> v;
void getIdx(int cnt, string temp) {
	if (cnt != 0 && temp == N) {
		for (auto curr : v) {
			ret += stoi(curr);
		}
		return;
	}
	char tmpBack = temp[temp.size() - 1];
	temp.pop_back();
	v.push_back(tmpBack + temp);
	getIdx(cnt + 1, tmpBack + temp);

}
int main() {
	cin >> N;
	getIdx(0, N);
	cout << ret << "\n";
	return 0;
}