#include <iostream>
#include <queue>
using namespace std;
using p = pair<int, int>;
int roffset[] = {-1, 0, 1, 0};
int coffset[] = {0, -1, 0, 1};
int arr[1010][1010];
int visited[1010][1010];
int T, N, M;
bool isIn(int r, int c){
    return (r>=0 && r<N && c>=0 && c<M);
}
void bfs(int r, int c){
    queue<p> q;
    q.push({r, c});
    visited[r][c] = true;
    while(!q.empty()){
        p curr = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            p next;
            next.first = curr.first + roffset[i];
            next.second = curr.second + coffset[i];
            if(!isIn(next.first, next.second)) continue;
            
            if(arr[next.first][next.second] >= T && !visited[next.first][next.second]){
                visited[next.first][next.second] = true;
                q.push(next);
            }
        }
    }
}
void checkArr(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<arr[i][j]<< " ";
        }
        cout<<"\n";
    }
}
int main(){
    cin >> N >> M;
    int temp[3]{};
    
    //1. 입력받기
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<3; k++){
                cin >> temp[k];
            }
            arr[i][j] = (temp[0] + temp[1] + temp[2])/3;
            
        }
    }
//    cout<<"****\n";
//    checkArr();
    
    cin >> T;
    int cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(!visited[i][j] && arr[i][j] >= T){
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout<<cnt<<"\n";
    return 0;
}

