#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
vector<int> adj[110];
bool visited[110];
int bfs(int start){
    int ret = 0; //각 레이어들의 합(케빈베이컨의 수)
    int bacon[110]{};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int layer = 0;
    while(!q.empty()){
        int qSize = q.size();
        for(int i=0; i<qSize; i++){
            int curr = q.front();
            bacon[curr] = layer;
            q.pop();
            for(auto next : adj[curr]){
                if(!visited[next]){
                    q.push(next);
                    visited[next] = true;
                }
            }
            
        }
        layer++;
    }
    for(int i=1; i<=N; i++){
//        cout<< "i : " << i <<" bacon[i] : "<< bacon[i]<<"\n";
        ret+=bacon[i];
    }
    return ret; }
int main(){
    cin >> N >> M;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int min = 1e9;
    int result = 0;
    for(int i=1; i<=N; i++){
        memset(visited,0,sizeof(visited));
        int kb = bfs(i);
//        cout<<"i: "<< i<<"kb : "<<kb<<"\n";
        if(kb < min) {
            min = kb;
            result = i;
        }
    }
    cout << result;
    return 0;
}

