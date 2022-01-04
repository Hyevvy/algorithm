#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M, D;
int arr[20][20];
int temp[20][20];
//배열을 복사하는 함수
void arrCpy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			temp[i][j] = arr[i][j];
		}
	}
}

bool hasEnemy(int t[20][20]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (t[i][j] == 1) return true;
		}
	}
	return false;
}

int getDist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

struct Dead {
	int r, c;
	Dead(int a, int b) {
		r = a, c = b;
	}
};

void move() {

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 1; j <= M; j++) {
			temp[i + 1][j] = temp[i][j];
		}
	}
	for (int j = 1; j <= M; j++) {
		temp[1][j] = 0;
	}

}
int attack(int a, int b, int c) {

	int archer[3] = { a,b,c };
	int cnt = 0;//죽인 적의 수

	//1. temp에 arr을 복사한다(원본 배열 손상을 막기 위함)
	memset(temp, 0, sizeof(temp));
	arrCpy();
	vector<Dead> v;
	while (1) {
		if (hasEnemy(temp) == false) return cnt;

		for (int k = 0; k < 3; k++) {
			Dead dead = Dead(0, 0);
			int minDist = 100000;

			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (temp[i][j] == 1 && getDist(N + 1, archer[k], i, j) <= D) {
						int d = getDist(N + 1, archer[k], i, j);
						if (d < minDist) {
							minDist = d;
							dead = { i, j };
						}
						else if (d == minDist) {
							if (dead.c > j) {
								dead = { i, j };
							}
						}
					}
				}
			}
			v.push_back(dead);
		}


		for (auto curr : v) {
			if (temp[curr.r][curr.c] != 0) {
				cnt++;
				temp[curr.r][curr.c] = 0;
			}
		}

		v.clear();
		move();
	}
}
int main() {
	cin >> N >> M >> D;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}

	int killedEnemy = 0;
	//1. 궁수의 위치 3개를 조합으로 구한다.
	for (int i = 1; i <= M; i++) {
		for (int j = i + 1; j <= M; j++) {
			for (int k = j + 1; k <= M; k++) {
				int ret = attack(i, j, k);
				if (killedEnemy < ret) {
					killedEnemy = ret;
				}
			}
		}
	}
	cout << killedEnemy;

	return 0;
}