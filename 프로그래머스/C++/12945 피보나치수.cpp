#include <string>
#include <vector>

using namespace std;
int dp[100010];
int solution(int n) {
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] % 1234567 + dp[i - 2] % 1234567;
    }


    return dp[n] % 1234567;
}