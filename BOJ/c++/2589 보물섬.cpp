#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int N, M;
char arr[52][52];
int roffset[] = {-1,0,0,1};
int coffset[] = {0,-1,1,0};
bool isIn(int r, int c){
    return r>=0 && r<N && c>=0 && c<M;
}
int bfs(int r, int c){
    int cnt = 0;
    queue<p> q;
    q.push({r, c});
    bool visited[52][52]{false,};
    visited[r][c] = true;
    while(!q.empty()){
        int qSize = q.size();
        for(int j=0; j<qSize; j++){
            int cr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nr = cr + roffset[i];
                int nc = cc + coffset[i];
                if(!isIn(nr, nc)|| visited[nr][nc]) continue;
                if(arr[nr][nc] == 'L'){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
            
        }
        cnt++;
    }

    return cnt;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    int maxVal = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'L'){
                maxVal = max(maxVal, bfs(i, j) - 1);
            }
        }
    }
    
    cout << maxVal;
    return 0;
}
