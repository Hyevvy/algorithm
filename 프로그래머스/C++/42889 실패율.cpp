#include <string>
#include <vector>
#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;
bool comp(pair<double, int>a, pair<double, int> b) {
    if (a.first == b.first) {
        return a < b;
    }
    return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v; // stage, ½ÇÆÐÀ²

    int prev = stages.size();
    sort(stages.begin(), stages.end());

    double failure = 0;
    for (int j = 1; j <= N; j++) {
        int num = 0;
        for (int i = 0; i < stages.size(); i++) {
            if (stages[i] == j) num++;
        }
        if (prev != 0) failure = (double)num / prev;
        else failure = 0;
        v.push_back({ failure, j });
        prev -= num;
    }
    sort(v.begin(), v.end(), comp);
    for (auto curr : v) {
        answer.push_back(curr.second);
    }
    return answer;
}