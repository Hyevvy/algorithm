#include <iostream>
#include <queue>
using namespace std;
int R, C;
int arr[501][501];
bool visited[501][501];
int roffset[4] = {0, 1, -1, 0};
int coffset[4] = {1, 0, 0, -1};

bool isIn(int a, int b){
    return ( a>=0 && a<R && b>=0 && b<C);
}
            
int bfs(int r, int c){
    int area = 0;
    visited[r][c] = true;
    queue<pair<int, int>> q;
    q.push({r,c});
    
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        area++;
        for(int i=0; i<4; i++){
            int nextFirst = curr.first + roffset[i];
            int nextSecond = curr.second + coffset[i];
            if(!isIn(nextFirst, nextSecond)) continue;
            if(!visited[nextFirst][nextSecond] && arr[nextFirst][nextSecond]){
                q.push({nextFirst, nextSecond});
                visited[nextFirst][nextSecond] = true;
            }
        }
        
    }
    return area;
}
int main(){
    cin >> R >> C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    int max = 0;
    //컴포넌트의 수 : 그림의 수
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(!visited[i][j] && arr[i][j]){
                int eachArea = bfs(i, j);
                if(max < eachArea){
                    max = eachArea;
                };
                cnt++;
            }
        }
    }
    
    cout<<cnt<<"\n"<<max;
    
    
    return 0;
}

