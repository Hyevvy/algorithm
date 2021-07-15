#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N;//가로 세로 최대 길이
int arr[25][25]{};
int visited[25][25]{};
int roffset[4]={0,1,0,-1};
int coffset[4]={-1,0,1,0};
int bfs(int r, int c){
    queue<pair<int, int>> q;
    q.push({r,c});
    visited[r][c] = 1;
    
    int ans = 0;
    while(!q.empty()){
        pair<int, int> curr = q.front();
        q.pop();
        ans++;
        for(int i=0; i<4; i++){
            int nr = curr.first + roffset[i];
            int nc = curr.second + coffset[i];
            if(nr >= N || nc >= N || nr <0 || nc <0 || visited[nr][nc]==1) continue;
            if(arr[nr][nc] == 1 ) {
                q.push({nr, nc});
                visited[nr][nc] = 1;
            }
        }
    }
    return ans;
}
int main(){
    cin >> N;
    
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++){
            arr[i][j] = s[j]-'0';
        }
    }
    
    
//
//    for(int i=0; i<N; i++){
//        for(int j=0; j<N; j++)
//            cout<<arr[i][j]<<" ";
//        cout<<"\n";
//    }
    
    vector<int> v;
    int cnt = 0;
    int state = 0;
    int num = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 1 && visited[i][j] == 0){
//                cout<< " i : " << i << " j : "<<j <<"\n";
                state = 1;
                num = bfs(i, j);
                cnt++;
                v.push_back(num);
            }
        }
    }
    cout<<cnt<<"\n";
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    cout<<v[i]<<"\n";
    return 0;
}

