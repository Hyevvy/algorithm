#include <iostream>
using namespace std;
int arr[26][26];
void check(int val) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == val) {
				arr[i][j] = 0;
				break;
			}
		}
	}
}

bool isBingo() {
	int result = 0;
	//가로 빙고 확인
	int bingo = 0;
	for (int i = 0; i < 5; i++) {
		bingo = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[i][j] == 0) bingo++;
		}
		if (bingo == 5) {
			result++;
		}
	}

	for (int i = 0; i < 5; i++) {
		bingo = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[j][i] == 0) bingo++;
		}
		if (bingo == 5) {
			result++;
		}
	}

	//오른쪽 하향 대각선
	bingo = 0;
	for (int i = 0, j = 0; i < 5; i++, j++) {
		if (arr[i][j] == 0) bingo++;
	}
	if (bingo == 5) result++;

	//오른쪽 상향 대각선

	bingo = 0;
	for (int i = 0, j = 4; i < 5; i++, j--) {
		if (arr[i][j] == 0) bingo++;
	}
	if (bingo == 5) result++;

	if (result >= 3) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	int num = 0;
	for (int i = 0, tmp; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			num++;
			cin >> tmp;
			check(tmp);
			if (isBingo()) {
				cout << num << "\n";
				return 0;
			}
		}
	}


	return 0;
}