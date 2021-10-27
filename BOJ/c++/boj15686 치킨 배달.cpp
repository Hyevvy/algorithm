#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
using p = pair<int, int>;
int n, m, idx, idxHouse;
int arr[55][55];
vector<p> v; //(1,2) (2,3)
p chicken[15];
p houses[110];
int retDist = 1e9;
int getDist(vector<p> chosens) {
    int ret = 0;//최종 치킨 거리
    for (int i = 0; i < idxHouse; i++) {
        p house = houses[i];
        int min = 1e9;
        for (auto chosenChicken : chosens) {
            int hereMin = abs(chosenChicken.first - house.first) + abs(chosenChicken.second - house.second);
            if (hereMin < min) min = hereMin;
        }
        //cout << "house : " << house.first << " " << house.second << " 일때: " << min << "\n";
        ret += min;

    }
    return ret; //치킨거리!
}


void getC(int cnt, int pos) {
    if (cnt == m) {
        int currDist = getDist(v);
        if (currDist < retDist) retDist = currDist;
    }
    else {
        for (int i = pos; i < idx; i++) {
            v.push_back(chicken[i]);
            getC(cnt + 1, i + 1);
            v.pop_back();
        }
    }
    return;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                houses[idxHouse] = { i, j };
                idxHouse++;
            }
            if (arr[i][j] == 2) {
                chicken[idx] = { i,j };
                idx++;
            }
        }
    }

    getC(0, 0);

    cout << retDist;

    return 0;
}