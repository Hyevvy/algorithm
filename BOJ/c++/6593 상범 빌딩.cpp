#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using p = pair<int, int>;
char arr[35][35][35];
int H, R, C;
int hoffset[] = {-1, 1, 0, 0, 0, 0};
int roffset[] = {0, 0, -1, 0, 0, 1};
int coffset[] = {0, 0, 0, -1, 1, 0};
bool visited[35][35][35];
struct Coord{
    int h, r, c;
    Coord(int x, int y, int z){
        h = x; r = y; c = z;
    }
};
Coord start = Coord(0,0,0);
bool isIn(int h, int r, int c){
    return h>=0 && h <H && r >=0 && r <R && c>=0&& c<C;
}
void checkArr(){
    cout<<"********\n";
    for(int i=0; i<H; i++){
        for(int j=0; j<R; j++){
            for(int k=0; k<C; k++){
                cout << arr[i][j][k] <<" ";
                
            }
            cout<<"\n";
        }
        cout<<"\n";
    }
}
int bfs(){
    queue<Coord> q;
    q.push(start);

    int cnt = 0;
    while(!q.empty()){
        int qSize = q.size();
        for(int i=0; i<qSize; i++){
            int ch = q.front().h;
            int cr = q.front().r;
            int cc = q.front().c;
            q.pop();
//            if(arr[ch][cr][cc] == 'E'){
//                return cnt;
//            }
            for(int j=0; j<6; j++){
                int nh = ch + hoffset[j];
                int nr = cr + roffset[j];
                int nc = cc + coffset[j];
                if(!isIn(nh, nr, nc) || visited[nh][nr][nc] || arr[nh][nr][nc]=='#') continue;
                q.push({nh,nr,nc});
                if(arr[nh][nr][nc] == 'E') return cnt + 1;
                arr[nh][nr][nc]='S';
                visited[nh][nr][nc] = true;
            }
        }
        cnt++;
    }
    return -1;
}
int main(){
    while(1){
        cin >> H >> R >> C;
        if(H==0 && R==0 && C==0) break;
        for(int i=0; i<H; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    cin >> arr[i][j][k];
                    if(arr[i][j][k]=='S'){
                        start = Coord(i, j, k);
                        visited[i][j][k] = true;
                    }
                }
            }
        }
        int ans = bfs();
        if(ans == -1) cout <<"Trapped!\n";
        else cout << "Escaped in "<< ans <<" minute(s).\n";
        memset(visited,0,sizeof(visited));
    }
    return 0;
}

