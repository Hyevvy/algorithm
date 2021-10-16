#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
using p = pair<int, int>;
int n;//편의점의 갯수
vector<p> locations;
bool visited[110];
bool bfs(int start, int end){
    visited[start] = true;
    queue<p> q;
    q.push(locations[start]);
    
    while(!q.empty()){
        p curr = q.front();
        q.pop();
        if(curr == locations[end]) return true;
        //#편의점을 입력받은 순서대로 들려야하는 것은 아님
        for(int i=1; i<=n+1; i++){
            if(visited[i] == true) continue;
            p next = locations[i];
            if(abs(next.first - curr.first) + abs(next.second - curr.second) <= 1000){
                visited[i] = true;
                q.push(next);
                
            }
        }
    }
    return false;
}
int main(){
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        locations.clear();
        memset(visited, 0, sizeof(visited));
        cin >> n;
        for(int j=0,u, v; j<n+2; j++){
            cin >> u >> v;
            locations.push_back({u, v});
        }
        //시작점과 종료점을 넘긴다.
        if(bfs(0, n+1) == true) cout<<"happy\n";
        else cout<<"sad\n";
    }
    return 0;
}

