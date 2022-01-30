#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int N, arr[310];
int ans = 0;
int dp[310][3];
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	dp[1][1] = dp[1][2] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i][1] = dp[i - 1][2] + arr[i];
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + arr[i];
	}

	cout << max(dp[N][1], dp[N][2]);
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}