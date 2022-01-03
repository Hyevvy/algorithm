#include <iostream>
#include <queue>
using namespace std;
int roffset[] = { -1, 0, 0, 1 };
int coffset[] = { 0, -1, 1, 0 };

int nroffset[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int ncoffset[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int W, H, K;
int arr[210][210];
bool visited[210][210][33];
struct Monkey {
    int r, c, isHorseMoving;
    Monkey(int x, int y, int z) {
        r = x, c = y, isHorseMoving = z;
    }
};

bool isIn(int r, int c) {
    return r >= 0 && r < H&& c >= 0 && c < W;
}
int bfs() {
    queue<Monkey> q;
    q.push({ 0, 0, 0 });
    visited[0][0][0] = true;
    int cnt = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int a = 0; a < qSize; a++) {
            int cr = q.front().r;
            int cc = q.front().c;
            int isHorseMoving = q.front().isHorseMoving;
            q.pop();
            if (cr == H - 1 && cc == W - 1) return cnt;
            for (int i = 0; i < 4; i++) {
                int nr = cr + roffset[i];
                int nc = cc + coffset[i];
                if (!isIn(nr, nc) || visited[nr][nc][isHorseMoving] || arr[nr][nc] == 1) continue;
                visited[nr][nc][isHorseMoving] = true;
                q.push({ nr, nc, isHorseMoving });
            }
            if (isHorseMoving < K) {
                for (int i = 0; i < 8; i++) {
                    int nr = cr + nroffset[i];
                    int nc = cc + ncoffset[i];
                    if (!isIn(nr, nc) || visited[nr][nc][isHorseMoving+1] || arr[nr][nc] == 1) continue;
                    visited[nr][nc][isHorseMoving+1] = true;
                    q.push({ nr, nc, isHorseMoving + 1 });
                }
            }
        }
        cnt++;
    }//while - closed
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> arr[i][j];
        }
    }
    cout << bfs();
    return 0;
}
