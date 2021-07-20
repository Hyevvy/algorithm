#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int M, N, K;
int arr[50][50];
bool visited[50][50];
int roffset[4] = {-1, 0, 1, 0};
int coffset[4] = {0, -1, 0, 1};
void bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        visited[r][c] = true;
        for(int i=0; i<4; i++){
            int nr = curr.first + roffset[i];
            int nc = curr.second + coffset[i];
            if(nr >= N || nc >= M || nr <0 || nc<0 || visited[nr][nc]==true ) continue;
            if(arr[nr][nc] == 1){
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
}
int main(){
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        memset(arr, 0, sizeof(arr));
        memset(visited,0, sizeof(visited));
        cin >> M >> N >> K;
        for(int j=0; j<K; j++){
            int r, c;
            cin >> r >> c;
            arr[c][r] = 1;
        }
        
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j]== 1 &&visited[i][j]==0) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<"\n";
    }

    return 0;
}

