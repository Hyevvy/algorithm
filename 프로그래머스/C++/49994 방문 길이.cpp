#include <string>
using namespace std;
bool arr[11][11][11][11];
bool isIn(int a) {
    return a >= 0 && a <= 10;
}
int solution(string dirs) {
    int answer = 0;
    int xs = 0, ys = 0, x = 5, y = 5;

    arr[0][0][0][0] = true;
    for (auto curr : dirs) {
        int tx = x; int ty = y;
        int prevx = x, prevy = y;
        int state = 0;
        if (curr == 'U' && isIn(++ty)) {
            y++;
            state = 1;
        }

        else if (curr == 'L' && isIn(--tx)) { x--; state = 1; }
        else if (curr == 'R' && isIn(++tx)) { x++; state = 1; }
        else if (curr == 'D' && isIn(--ty)) { y--; state = 1; }
        if (arr[prevx][prevy][x][y] == false && state == 1) {
            answer++;
            arr[prevx][prevy][x][y] = true;
            arr[x][y][prevx][prevy] = true;
        }
    }

    return answer;
}