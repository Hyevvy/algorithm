#include <iostream>
#include <stack>
using namespace std;
string getKeyloger(string s) {
	//TODO: S를 size만큼 순회하면서
	//'-'면 pop
	//< 화살표의 입력을 움직임?
	//ex : A-B<C : CB
	string retS;//키로거
	int idx = 0;//커서의 위치
	int sSize = s.size();
	for (int i = 0; i < sSize; i++) {
		if (s[i] == '-' && idx != 0) {
			retS.pop_back();
			idx--;
			idx = idx < 0 ? 0 : idx;
		}
		else if (s[i] == '<') {
			idx--;
			idx = idx < 0 ? 0 : idx;
		}
		else if (s[i] == '>') {
			idx++;
		}
		else {
			//TODO: retS[idx]에 s[i]를 넣어야함
			//outOf...
			//idx 는 1인데 retS는 2
			string temp;
			int retSize = retS.size();
			for (int i = idx; i < retSize; i++) {
				temp.push_back(retS[i]);
			}
			for (int i = idx; i < retSize; i++) {
				retS.pop_back();
			}
			retS.push_back(s[i]);
			retS += temp;
			idx++;
		}
	}
	return retS;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	string inputS;
	for (int i = 0; i < tc; i++) {
		cin >> inputS;
		cout << getKeyloger(inputS)<<"\n";
	}

	return 0;
}