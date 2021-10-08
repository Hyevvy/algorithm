#include <iostream>
#include <queue>
using namespace std;
int N, K;
int offset[] = {-1, 1};
bool visited[200001];
bool isIn(int n){
    return n>=0 && n<=200000;
}
int bfs(){
    int time = 0;
    queue<int> q;
    q.push(N);
    visited[N] = true;
    while(!q.empty()){
        int qSize = q.size();
        time++;
        for(int i=0; i<qSize; i++){
            //레이어별로 방문
            int curr = q.front();
            if(curr == K) return time-1;
            q.pop();
            visited[curr] = true;
            for(int j=0; j<3; j++){
               int next = 0;
                if(j==2){
                    next = curr + curr;
                }
                else next = curr + offset[j];
                
                if(!isIn(next)) continue;
//                cout<<"현재 next: "<<next <<"현재 time " <<time<<"\n";
                if(!visited[next]){
                    q.push(next);
                    visited[next] =true;
                    
                }
            }
        }
    }
    return time;
}
int main(){
    cin >> N >> K;
    cout << bfs();
    return 0;
}
