#include <iostream>
#include <vector>
using namespace std;
vector<int> adj[51];
bool visited[51];
int leaf;
void dfs(int curr){
    int state = 0; //next가 있는경우 1
    visited[curr] = true;
    for(int next : adj[curr]){
        if(!visited[next]) {
            dfs(next);
            state = 1;
        }
    }
    if(state == 0) leaf++;
}
int main(){
    int n;//노드(정점의 개수)
    cin >> n;
    
    int rootNode = 0;
    int deletedNode = 0;
    for(int i=0, v; i<n; i++){
        cin >> v;
        if(v==-1) rootNode = i;
        else adj[v].push_back(i);
    }
    cin >> deletedNode;
    if(deletedNode == rootNode) cout<<"0\n";
    else {
        //1. 삭제할 노드들을 순회하며 방문처리(삭제용)
        dfs(deletedNode);
        leaf = 0;
        //2. 방문된 노드들을 제외하고 순회하며
        //방문처리가 안 되어있고, next가 없는게
        //leaf노드이다.
        dfs(rootNode);
        cout<<leaf;
    }
    return 0;
}

