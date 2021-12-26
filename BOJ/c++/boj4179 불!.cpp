#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int R, C;
char arr[1010][1010];
int roffset[] = {-1, 0, 0, 1};
int coffset[] = {0, -1, 1, 0};
bool visitedJ[1010][1010];
bool visitedF[1010][1010];
queue<p> J;
queue<p> F;
bool isIn(int r, int c){
    return r>=0 && r<R && c>=0 && c<C;
}

bool canExit(int r, int c){
    if(r == 0 || c == 0 || r == R-1 || c == C-1) return true;
    return false;
}
void checkMap(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
        cout << arr[i][j] <<" ";
        cout <<"\n";
    }
}

int bfs(){
    int ret = 0;
    while(!J.empty() || !F.empty()){
        int fSize = F.size();
        for(int i=0; i<fSize; i++){
            int cr = F.front().first;
            int cc = F.front().second;
            F.pop();
            
            for(int j=0; j<4; j++){
                int nr = cr + roffset[j];
                int nc = cc + coffset[j];
                if(!isIn(nr, nc) || visitedF[nr][nc] || arr[nr][nc]=='#') continue;
                visitedF[nr][nc] = true;
                F.push({nr, nc});
                arr[nr][nc] = 'F';
            }
        }
        
        
        
        int jSize = J.size();
        for(int i=0; i<jSize; i++){
            int cr = J.front().first;
            int cc = J.front().second;
            J.pop();
            if(canExit(cr, cc)) return ret + 1;
            
            for(int j=0; j<4; j++){
                int nr = cr + roffset[j];
                int nc = cc + coffset[j];
                if(!isIn(nr, nc) || visitedJ[nr][nc] || arr[nr][nc]=='#'
                   || arr[nr][nc]=='F') continue;

                visitedJ[nr][nc] = true;
                J.push({nr, nc});
                arr[cr][cc] ='.';
                arr[nr][nc] ='J';
            }
        }
        ret++;
    }
    
    return -1;
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'J') {
                J.push({i, j});
                visitedJ[i][j] = true;
            }
            else if(arr[i][j] == 'F') {
                F.push({i, j});
                visitedF[i][j] = true;
            }
        }
            
    }
    
    int ans = bfs();
    if(ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans<<"\n";
    return 0;
}
