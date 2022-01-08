#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int T;
bool shouldReverse;
bool isError; 
void doProm(string P, deque<int>& dq, int arrSize) {
    shouldReverse = false;
    isError = false;
    for (int i = 0; i < P.size(); i++) {
        if (P[i] == 'R') shouldReverse = !shouldReverse;
        else if (P[i] == 'D') {
            if (dq.empty()) {
                cout << "error\n";
                isError = true;
                return;
            }
            if (!shouldReverse) dq.pop_front();
            else dq.pop_back();
        }
    }
    return ;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tmp, arrSize;
    string P;
    char gc;
    cin >> T;

    for (int i = 0; i < T; i++) {
        deque<int> dq;
        cin >> P >> arrSize;
        cin >> gc; // [
        for (int j = 0; j < arrSize; j++) {
                cin >> tmp;  // ? 
                cin >> gc; // , ]
                dq.push_back(tmp);
        }
        if (!arrSize) cin >> gc;
        doProm(P, dq, arrSize); // error
        if (isError) continue;
        cout << '[';
        if (shouldReverse) {
            for (int i = dq.size() - 1; i >= 0; i--) {
                cout << dq[i];
                if (i != 0) cout << ',';
            }
        }
        else {
            for (int i = 0; i < dq.size(); i++) {
                cout << dq[i];
                if (i != dq.size() - 1) cout << ',';
            }
        }
        cout << ']' << '\n';
    }
    return 0;
}
