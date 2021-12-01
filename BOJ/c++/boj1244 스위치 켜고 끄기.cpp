#include <iostream>
using namespace std;
int N, students;
int bulbs[110];

void switchBulb(int g, int n) {
    if (g == 1) {
        //1. 남자인 경우
        for (int i = 1; i <= N; i++) {
            if(i % n == 0) bulbs[i] = !bulbs[i];
        }
    }
    else {
        int j = n, k = n;
        //2. 여자인 경우
            while (1) {
                if (j < 1 || k > N) break;
                if (bulbs[j] != bulbs[k]) break;
                j--; k++;
            }
            for (int a = j + 1; a < k; a++) {
                bulbs[a] = !bulbs[a];
            }
        
    }
}

void checkBulbs() {
    for (int i = 1; i <= N; i++) {
        cout << bulbs[i] << " ";
        if (i % 20 == 0) {
            cout << "\n";
        }
    }
}

int main() {
    int gender, num;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> bulbs[i];
    }

    cin >> students;
    for (int i = 0; i < students; i++) {
        cin >> gender >> num;
        switchBulb(gender, num);
        
    }
    checkBulbs();

    return 0;
}
