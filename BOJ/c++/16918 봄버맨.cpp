#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int R, C, N;
int roffset[] = {-1, 0, 0, 1};
int coffset[] = {0, -1, 1, 0};
int arr[210][210];
void checkArr(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}
bool isIn(int r, int c){
    return r>=0 && r<R && c>=0 &&c<C;
}
void bomb(){
    queue<p> q;
    bool visited[210][210]{false,};
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == 1){
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    while(!q.empty()){
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();
        arr[cr][cc] = 0;
        for(int i=0; i<4; i++){
            int nr = roffset[i] + cr;
            int nc = coffset[i] + cc;
            if(!isIn(nr, nc) || visited[nr][nc]) continue;
            if(arr[nr][nc]!=0){
                visited[nr][nc] = true;
                arr[nr][nc] = 0;
            }
        }
    }
}

void getMapToAnswer(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == 0){
                cout<<".";
            }
            else cout <<"O";
        }
        cout<<"\n";
    }
}
void installBomb(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] == 0){
                arr[i][j] = 3;
            }
        }
    }
}

void countDownBomb(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(arr[i][j] != 0){
                arr[i][j]--;
            }
        }
    }
}
int main(){
    cin >> R >> C >> N;
    char tmp;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> tmp;
            if(tmp=='.'){
                arr[i][j] = 0;
            }
            else if(tmp=='O'){
                arr[i][j] = 3;
            }
        }
    }
    
    int time = 1;
    countDownBomb();
    while(1){
        if(time>=N) break;
        
        if(time>=N) break;
        time++;
        countDownBomb();
        installBomb();
        if(time>=N) break;
        time++;
        bomb();
        countDownBomb();
    }
 
    
    getMapToAnswer();
    
    return 0;
}
  
