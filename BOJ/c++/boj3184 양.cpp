#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
char arr[260][260];
bool visited[260][260];
int roffset[] = {-1, 0, 1, 0};
int coffset[] = {0, -1, 0, 1};
int R, C;
void checkArr(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++)
            cout<<arr[i][j];
        cout<<"\n";
    }
    
}
bool isIn(int r, int c){
    return r>=0 && r<R && c>=0 && c<C;
}
p bfs(int r, int c){
    queue<p> q;
    q.push({r, c});
    visited[r][c] = true;
    int sheep = 0;
    int wolf = 0;
    while(!q.empty()){
        p curr = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            p next;
            next.first = curr.first + roffset[i];
            next.second = curr.second + coffset[i];
            if(!isIn(next.first, next.second)) continue;
            if(!visited[next.first][next.second]){
                if(arr[next.first][next.second]=='#') continue;
                if(arr[next.first][next.second]=='v'){
                    wolf++;
                }
                else if(arr[next.first][next.second]=='o'){
                    sheep++;
                }
                
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
    if(sheep > wolf) {
        wolf = 0;
    }
    else sheep = 0;
    return {sheep, wolf};
}

int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
        }
    }

    p res = {0, 0};
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j]){
                p temp = bfs(i, j);
                res.first += temp.first;
                res.second += temp.second;
            }
        }
    }
    
    cout <<res.first << " " << res.second <<"\n";
    
    return 0;
}
