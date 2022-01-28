#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int coins[] = { 500,100,50,10,5,1 };
int main() {
	cin >> N;
	int ret = 0; //µ¿Àü ¼ö
	for (int i = 1000 - N; i > 0; ) {
		for (int j = 0; j < 6; j++) {
			if (i >= coins[j]) {
				ret += i / coins[j];
				i = i % coins[j];
			}
		}
	}

	cout << ret << "\n";
	return 0;
}