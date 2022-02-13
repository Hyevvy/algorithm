#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, R;
vector<int> V[100010];
int visited[100010];
void bfs(){
    memset(visited, -1, sizeof(visited));
    queue<int> q;
    q.push(R);
    visited[R] = 0;
    int cnt = 1;
    while(!q.empty()){
        int qSize = q.size();
        for(int i=0; i<qSize; i++){
            int curr = q.front();
            q.pop();
            for(auto next : V[curr]){
                if(visited[next]==-1 && next != R){
                    q.push(next);
                    visited[next] = cnt;
                }
            }
        }
        cnt++;
    }
}
int main(){
    cin >> N >> M >> R;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
    }
    bfs();
    for(int i=1; i<=N; i++){
        cout << visited[i]<<"\n";
    }
    return 0;
}
