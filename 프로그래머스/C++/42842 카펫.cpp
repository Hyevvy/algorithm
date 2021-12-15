#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<pair<int, int>> cases;
int getOutline(int r, int c) {
    return r * 2 + c * 2 - 4;
}
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;

    for (int i = 1; i < sum; i++) {
        if (sum % i == 0) {
            cases.push_back({ i, sum / i });
        }
    }

    for (auto curr : cases) {
        int width = max(curr.first, curr.second);
        int height = min(curr.first, curr.second);
        if (getOutline(width, height) == brown) {
            answer.push_back(width);
            answer.push_back(height);
            return answer;
        }
    }
    return answer;
}