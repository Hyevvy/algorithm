#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
using p = pair<int, int>;
int R, C;
int arr[110][110];
int roffset[4]={-1,0,0,1};
int coffset[4]={0,-1,1,0};
int nuckDist[110][110];
int chDist[110][110];
int swingsDist[110][110];
vector<p> devils[3];

bool isIn(int r, int c){
    return (r>=1 &r<=R && c>=1 && c<=C);
}

void bfs(){
    int times = 0;
    memset(nuckDist, -1, sizeof(nuckDist));
    memset(swingsDist, -1, sizeof(swingsDist));
    memset(chDist, -1, sizeof(chDist));
    
    queue<p> nucks;
    nucks.push({devils[0][0].first, devils[0][0].second});
    nuckDist[devils[0][0].first][devils[0][0].second] = 0;
    
    queue<p> swings;
    swings.push({devils[1][0].first, devils[1][0].second});
    swingsDist[devils[1][0].first][devils[1][0].second] = 0;
    
    queue<p> ch;
    ch.push({devils[2][0].first, devils[2][0].second});
    chDist[devils[2][0].first][devils[2][0].second] = 0;
    
    
    while( !nucks.empty() || !swings.empty() || !ch.empty()){
        times++;
        //각 qSize별로 돌림
        int qNuckSize = nucks.size();
        for(int i=0; i<qNuckSize; i++){
            p qNuckFront = nucks.front();
            nucks.pop();
            
            for(int j=0; j<4; j++){
                int nr = qNuckFront.first + roffset[j];
                int nc = qNuckFront.second + coffset[j];
                if(!isIn(nr, nc) || arr[nr][nc] == 1) continue;
                if(nuckDist[nr][nc] == -1){
                    nuckDist[nr][nc] = times;
                    nucks.push({nr, nc});
                }
            }
        }
        
        int qSwingsSize = swings.size();
        for(int i=0; i<qSwingsSize; i++){
            p qSwingFront = swings.front();
            swings.pop();
            for(int j=0; j<4; j++){
                int nr = qSwingFront.first + roffset[j];
                int nc = qSwingFront.second + coffset[j];
                if(!isIn(nr, nc) || arr[nr][nc] == 1) continue;
                if(swingsDist[nr][nc] == -1){
                    swingsDist[nr][nc] = times;
                    swings.push({nr, nc});
                }
            }
        }
        
        int qChSize = ch.size();
        for(int i=0; i<qChSize; i++){
            p qChFront = ch.front();
            ch.pop();
            for(int j=0; j<4; j++){
                int nr = qChFront.first + roffset[j];
                int nc = qChFront.second + coffset[j];
                if(!isIn(nr, nc) || arr[nr][nc] == 1) continue;
                if(chDist[nr][nc] == -1){
                    chDist[nr][nc] = times;
                    ch.push({nr, nc});
                }
            }
        }
           
    }
    
}

int main(){
    cin >> R >> C;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++)
        scanf("%1d", &arr[i][j]);
    }
    
    for(int i=0; i<3; i++){
        int a, b;
        cin >> a >> b;
        devils[i].push_back({a, b});
    }
    bfs();

    int minTime = 1e9;
    int times = 0;
    int ret = 0;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(chDist[i][j]!= -1 && swingsDist[i][j] != -1 && nuckDist[i][j]!=-1){
                times= max({chDist[i][j], swingsDist[i][j], nuckDist[i][j]});
                minTime = min(times, minTime);
            }
        }
    }
    
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(chDist[i][j]!= -1 && swingsDist[i][j] != -1 && nuckDist[i][j]!=-1){
                times= max({chDist[i][j], swingsDist[i][j], nuckDist[i][j]});
                if(minTime == times) ret++;
            }
        }
    }
    
    if(times == 0) cout <<"-1\n";
    else cout << minTime <<"\n" << ret << "\n";

    return 0;
}
