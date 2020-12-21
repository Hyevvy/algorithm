#include <iostream>
#include <vector>
using namespace std;
int checkSum(vector<int> MarioEat) {
    int sum = 0;
    for (int i = 0; i < MarioEat.size(); i++) {
        sum += MarioEat[i];
    }
    return sum;
}
int checkNear100(int curr) {
    int result = 100 - curr;
    if (result < 0) return result * (-1);
    return result;
}
int main() {
    vector <int> MarioEat;
    vector <int> MarioEatSum;
    int currMush;
    for (int i = 0; i < 10; i++) {
        cin >> currMush;
        MarioEat.push_back(currMush);
        MarioEatSum.push_back(checkSum(MarioEat));
    }
    int index = 0;
    int min = checkNear100(MarioEatSum[0]);//0번째값의 100과의 차이
    for (int i = 1; i < MarioEatSum.size(); i++) {
        if (checkNear100(MarioEatSum[i]) <= min) {
            min = checkNear100(MarioEatSum[i]);
            index = i;
        }
    }
    if (index != 0 && min == checkNear100(MarioEatSum[0])) {
        //0번째는 아닌데 0번째 값과 100과의 차이값이 같다면
        //둘 중 더 큰 값을 출력해야한다.
        if (MarioEatSum[index] >= MarioEatSum[0]) cout << MarioEatSum[index];
        else cout << MarioEatSum[0] << "\n";
    }
    else {
        cout << MarioEatSum[index] << "\n";
    }
    return 0;
}

