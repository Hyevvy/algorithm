#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int N;
vector<int> v[410];
int classRoom[50][50];
int emptySeat[50][50];
int roffset[] = {-1, 0, 0, 1};
int coffset[] = {0, -1, 1, 0};
bool isIn(int r, int c){
    return r>=1 && r<=N && c>=1 && c<=N;
}
void checkClassRoom(){
    for(int i=1;i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << classRoom[i][j] <<" ";
        }
        cout<<"\n";
    }
}

int getEmptySeat(int r, int c){
    int emptySeat = 0;
    for(int i=0; i<4; i++){
        int nr = r + roffset[i];
        int nc = c + coffset[i];
        if(!isIn(nr, nc)) continue;
        if(classRoom[nr][nc] == 0) emptySeat++;
    }
    return emptySeat;
}

int getCloseFriends(int r, int c, vector<int> curr){
    int friends = 0;
    for(int i=0; i<4; i++){
        int nr = r + roffset[i];
        int nc = c + coffset[i];
        if(!isIn(nr, nc)) continue;
        for(int j=0; j<curr.size(); j++){
            if(classRoom[nr][nc] == curr[j]){
                friends++;
            }
        }
    }
    return friends;
}
bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}
void fillClassRoom(int target, vector<int>& curr){
    vector<pair<int, int>> cf[4]; //idx: 인접한 친한친구수 first:r, second:c
    int closeFriends = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(classRoom[i][j] == 0){
                int temp = getCloseFriends(i, j, curr);
                cf[temp].push_back({i,j});
                closeFriends = max(closeFriends, temp);
                
            }
        }
    }
    
    if(cf[closeFriends].size() != 1){
        int tr = 0, tc = 0;//앉힐 자리
        int etSeatResult = 0;
        for(auto curr :cf[closeFriends]){
            int nr = curr.first;
            int nc = curr.second;
            int emptySeat = getEmptySeat(nr, nc);
            etSeatResult = max(emptySeat, etSeatResult);
        }
    
        vector<pair<int,int>> pos;
        for(auto curr : cf[closeFriends]){
            int nr = curr.first;
            int nc = curr.second;
            int emptySeat = getEmptySeat(nr, nc);
            if(etSeatResult == emptySeat){
                pos.push_back({nr, nc});
            }
        }
        sort(pos.begin(), pos.end(), cmp);
        classRoom[pos[0].first][pos[0].second] = target;
        
    }
    else {
        //앉혀버리기!
        int nr = cf[closeFriends][0].first;
        int nc = cf[closeFriends][0].second;
        classRoom[nr][nc] = target;
    }
}
int getSati(int r, int c, int target){
    int sati = 0;
    
    for(int i=0; i<4; i++){
        int nr = r + roffset[i];
        int nc = c + coffset[i];
        if(!isIn(nr, nc)) continue;
        for(int j=0; j<v[target].size(); j++){
            if(classRoom[nr][nc] == v[target][j]){
                sati++;
            }
        }
    }
    if(sati == 0) return 0;
    else if(sati == 1) return 1;
    else if(sati == 2) return 10;
    else if(sati == 3) return 100;
    else if(sati == 4) return 1000;
    
    return sati;
}
int getResult(){
    int ret = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ret += getSati(i, j, classRoom[i][j]);
        }
    }
    return ret;
}
int main(){
    cin >> N;
    for(int i=0, a, b, c, d, e; i<N*N; i++){
        cin >> a >> b >> c >> d >> e;
        v[a].push_back(b);
        v[a].push_back(c);
        v[a].push_back(d);
        v[a].push_back(e);
        fillClassRoom(a, v[a]);
       // checkClassRoom();
    }
    cout << getResult();
    
    return 0;
}
