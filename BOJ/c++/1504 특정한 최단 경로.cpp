#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using p = pair<int, int>;
vector<p> V[810];
int N, E, V1, V2;
bool canGO = true;
int dijk(int start, int end){
    int dists[810];
    for (int i = 1; i <= N; i++) {
            dists[i] = 1e9;
    }
    priority_queue<p> pq; // first : cost, second : v
    dists[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        int cost = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        for(auto [nextV, nextC] : V[curr]){
            if(dists[nextV] > nextC + dists[curr]){
                dists[nextV] = nextC + dists[curr];
                pq.push({dists[nextV], nextV});
            }
            
        }
    }
    if(dists[end] == 1e9) canGO = false;
    return dists[end];
}

int getMinDists(){
    //1->V1->V2->N
    int caseA = dijk(1, V1) + dijk(V1, V2) + dijk(V2, N);
    
    //1->V2->V1->N
    int caseB = dijk(1, V2) + dijk(V2, V1) + dijk(V1, N);
    
    int ret = min(caseA, caseB);
    if(!canGO) return -1;
    else return ret;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> E;
    for(int i=0, u, v, w; i<E; i++){
        cin >> u >> v >> w;
        V[u].push_back({v, w});
        V[v].push_back({u, w});
    }
    cin >> V1 >> V2;
    
    cout<<getMinDists();
    return 0;
}

