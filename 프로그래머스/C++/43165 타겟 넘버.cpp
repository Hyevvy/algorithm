#include <string>
#include <vector>
#include <queue>
using namespace std;
int ret, nSize;
void dfs(int cnt, int target, int sum, vector<int>& numbers) {
    if (cnt == nSize) {
        if (target == sum) ret++;
        return;
    }

    dfs(cnt + 1, target, sum - numbers[cnt], numbers);
    dfs(cnt + 1, target, sum + numbers[cnt], numbers);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    nSize = numbers.size();
    dfs(0, target, 0, numbers);

    return ret;
}