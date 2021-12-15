#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using pr = pair<int,int>;
int roffset[] ={-1,0,0,1};
int coffset[] ={0,-1,1,0};
int dist[10][10];
bool isIn(int r, int c){
    return r>=0 && r<5 && c>=0 && c<5;
}
bool bfs(vector<string>p, int r, int c){
    memset(dist, 0, sizeof(dist));
    queue<pr> q;
    q.push({r,c});
    dist[r][c]=1;
    int currDist = 1;
    while(!q.empty()){
            int cr = q.front().first;
            int cc = q.front().second;

            q.pop();
            if(dist[cr][cc] > 2) continue;
            if(!(cr==r && cc==c) && p[cr][cc] == 'P') return false;
            
            for(int j=0; j<4; j++){
                int nr = cr + roffset[j];
                int nc = cc + coffset[j];
                
                if(!isIn(nr, nc)) continue;
               
                if(dist[nr][nc]!=0) continue;
                if(p[nr][nc] == 'X') continue; 
                dist[nr][nc] = currDist;
                q.push({nr,nc});
            } 
        currDist++;
    }
    
    
    return true;
}

bool isOK(vector<string> p){
    for(int i=0; i<p.size(); i++){
        for(int j=0; j<p[i].size(); j++){
            if(p[i][j] == 'P'){
                if(bfs(p, i, j) == false) return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(auto place : places){
        if(isOK(place)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}