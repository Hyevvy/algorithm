#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;
using p = pair<int, int>;
int N, M, D;
int arr2[16][16];
int arr[16][16];
vector<p> v;
vector<p> coord;
set<p> willremove;
vector<int> dists;
bool hasEnemy(int arr[16][16]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            if (arr[i][j] == 1) return true;
    }
    return false;
}
int getDist(int cr, int cc, int nr, int nc) {
    return abs(cr - nr) + abs(cc - nc);
}
bool isIn(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}

void checkTemp(int temp[16][16]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << temp[i][j] << " ";
        cout << "\n";
    }
}

int getPower(int temp[16][16]) {
    int cnt = 0; // 제거한 적의 수
    while (1) {
        willremove.clear();
        if (hasEnemy(temp) == false) return cnt;
        for (auto curr : v) {
            int cr = curr.first, cc = curr.second;
            int minDist = 1e9;
            p removeCoor = { 0,0 };
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (temp[i][j] == 0) continue;
                    if (getDist(cr, cc, i, j) <= D) {
                        if (minDist > getDist(cr, cc, i, j)) {
                            minDist = getDist(cr, cc, i, j);
                            removeCoor = { i,j };
                        }
                        else if (minDist == getDist(cr, cc, i, j)) {
                            if (removeCoor.second > j) {
                                removeCoor = { i,j };
                            }
                        }
                    }
                }
            }
            if (!(removeCoor.first == 0 && removeCoor.second == 0)) {
                willremove.insert(removeCoor);
            }

        }
        for (auto a : willremove) {
            temp[a.first][a.second] = 0;
        }

        //궁수의 공격이 끝나면 적은 한칸씩 내려간다.
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j < M; j++) {
                temp[i + 1][j] = temp[i][j];
                if (i == 0) {
                    temp[i][j] = 0;
                }
            }
        }

        for (auto a : willremove) {
            cnt++;
        }
    }//while문 끝
    return -1;
}
void getThree(int cnt, int pos) {
    if (cnt == 3) {
        int ans = getPower(arr);
        dists.push_back(ans);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                arr[i][j] = arr2[i][j];
        }
        return;
    }
    for (int j = pos; j < M; j++) {
        v.push_back({ N, j });
        getThree(cnt + 1, pos + 1);
        v.pop_back();
    }
}

int main() {
    cin >> N >> M >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            arr2[i][j] = arr[i][j];
        }
    }

    getThree(0, 0);

    sort(dists.begin(), dists.end());
    cout << dists[dists.size() - 1] << "\n";

    return 0;
}
