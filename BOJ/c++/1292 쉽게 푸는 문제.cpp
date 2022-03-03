#include <iostream>
using namespace std;
int arr[1011];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int start, end;
	cin >> start >> end;


	//반복문을 돌리다보면 idx가 end 범위를 초과할 수 있음
	//=> Out Of Bounds
	int idx = 0;
	for (int i = 1; i < end + 1 && idx < end; i++) {
		for (int j = 0; j < i && idx < end; j++) {
			arr[idx] = i;
			idx++;
		}
	}

	int sum = 0;
	for (int i = end - 1; i >= start - 1; i--) {
		sum += arr[i];
	}
	cout << sum << "\n";
	return 0;
}