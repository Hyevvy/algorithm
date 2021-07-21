#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> v[100];
bool visited[100];
int bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int ans = 0;
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(int i=0; i<v[curr].size(); i++){
            int next = v[curr][i];
            if(visited[next] == false) {
                visited[next] = true;
                q.push(next);
                ans++;
            }
        }
    }
    return ans;
}



int main(){
    int node, edge; //컴퓨터의 수, 연결된 간선의 수
    cin >> node >> edge;
    
    for(int i=0; i<edge; i++){
        int a, b;
        cin >> a >> b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }
    
    cout << bfs(0) <<"\n";

    return 0;
}
