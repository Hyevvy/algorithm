#include <iostream>
#include <vector>
using namespace std;
int tc, K;
int arr[50];
vector<int> v;
void setTn() {
	for (int i = 1; i <= 45; i++) {
		arr[i] = i * (i + 1) / 2;
	}
}

bool isPossible(int K) {
	for (int i = 1; i <= 45; i++) {
		for (int j = 1; j <= 45; j++) {
			for (int k = 1; k <= 45; k++) {
				if (arr[i] + arr[j] + arr[k] == K) return true;
				if (arr[i] + arr[j] + arr[k] > K) break;
			}
		}
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	setTn();
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> K;
		if (isPossible(K)) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}