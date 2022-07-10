#include <string>
#include <vector>

using namespace std;
int getResultNum(int n) {
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) ret++;
    }
    return ret;
}
int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; i++) {
        int ans = getResultNum(i);
        if (ans % 2 == 0) answer += i;
        else answer -= i;
    }

    return answer;
}