#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int>> sco;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    int state = 0;

    for (auto curr : scoville) {
        if (curr < K) {
            sco.push(curr);
        }
    }

    while (!sco.empty()) {
        if (sco.top() >= K) break;

        int one = sco.top();
        sco.pop();

        if (sco.empty()) return -1;
        int two = sco.top();
        sco.pop();
        //  cout << one << " " << two << "\n";
        sco.push(one + two * 2);
        answer++;
    }
    return answer;
}