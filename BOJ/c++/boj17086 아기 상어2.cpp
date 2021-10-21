#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int n, m;
int arr[51][51];
bool visited[51][51];
int roffset[]={-1,0,1,0, -1, -1, 1, 1,};
int coffset[]={0,-1,0,1, -1, 1, -1, 1 };
queue<p> q;
void checkArr(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        cout<<visited[i][j]<<" ";
        cout<<"\n";
    }
    
}
bool isIn(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}
int bfs(){
    int ret = 0;
    while(!q.empty()){
        int qSize = q.size();
//        cout<<"*****\n";
//        checkArr();
        for(int i=0; i<qSize; i++){
            //레이어별로..
            p curr = q.front();
            q.pop();
            for(int j=0; j<8; j++){
                int nr = curr.first + roffset[j];
                int nc = curr.second + coffset[j];
                if(!isIn(nr, nc) || visited[nr][nc]) continue;
                if(arr[nr][nc] == 0){
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                    arr[nr][nc] = 1;
                }
            }
        }
        ret++;
    }
    return ret - 1;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1) {
                q.push({i,j});
                visited[i][j]= true;
            }
        }
    }
    
    cout << bfs();
    
    return 0;
}
