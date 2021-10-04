#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, start; //N:정점, M:간선의 개수, start: 탐색을 시작할 정점의 번호
vector<int> adj[1001];
vector<int> order;
bool visited[1001];
void bfs(int start){
    queue<int> q;
    q.push({start});
    visited[start] = true;
    
    while(!q.empty()){
        int curr = q.front();
        order.push_back(curr);
        q.pop();
    
        for(int i=0; i<adj[curr].size(); i++){
            int next = adj[curr][i];
            if(!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void dfs(int start){
    visited[start] = true;
    order.push_back(start);
    for(int i=0; i<adj[start].size(); i++){
        int next = adj[start][i];
        if(!visited[next]) {
            dfs(next);
        }
    }
}

int main(){
    cin >> N >> M >> start;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    for(int i=1; i<=N; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    //dfs출력
    dfs(start);
    for(int i=0; i<order.size(); i++)
        cout<<order[i] << " ";
    cout<<"\n";
    
    memset(visited,0,sizeof(visited));
    order.clear();
    
    //bfs출력
    bfs(start);
    for(int i=0; i<order.size(); i++)
        cout<<order[i] << " ";
    cout<<"\n";
    
    return 0;
}

