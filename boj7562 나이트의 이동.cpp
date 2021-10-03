#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
using p = pair<int, int>;
int arr[301][301];
int roffset[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int coffset[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int l;
p curr, goal;
bool isIn(int r, int c){
    return (r>=0 && r<l && c>=0 && c<l);
}
int bfs(){
    memset(arr, 0, sizeof(arr));
    
    int time = 0; //몇 번만에 갈 수 있는지
    queue<p> q;
    q.push(curr);
    arr[curr.first][curr.second] = 1;
    while(!q.empty()){
        int qSize = q.size();
        for(int j=0; j<qSize; j++){
            curr = q.front();
            q.pop();
           
            for(int i=0; i<8; i++){
                int nextFirst = curr.first + roffset[i];
                int nextSecond = curr.second + coffset[i];
                if(!isIn(nextFirst, nextSecond)) continue;
                
                if(nextFirst == goal.first && nextSecond == goal.second){
                    return time+1;}
                
                if(arr[nextFirst][nextSecond] == 0){
                    //방문을 한 적이 없다면 방문 처리하고 큐에 넣어준다.
                    arr[nextFirst][nextSecond] = 1;
                    q.push({nextFirst, nextSecond});
                }
            }
        }
        time++; //레이어별로
        
    }
    return 0;
}
int main(){
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        cin >> l >> curr.first >> curr.second >> goal.first >> goal.second;
        if(curr.first == goal.first && curr.second == goal.second) cout<<"0";
        else cout<<bfs();
        cout<<"\n";
    }
    return 0;
}

