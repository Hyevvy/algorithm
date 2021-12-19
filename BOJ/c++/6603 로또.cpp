#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int K;
int arr[15];
bool visited[15];
vector<vector<int>> v;
vector<int> cases;
void pushCases(){
    v.push_back(cases);
}
void getAllCases(int pos, int cnt){
    if(cnt == 6){
        //basecase
      
        for(auto curr : cases){
            cout << curr <<" ";
        }
        cout <<"\n";

        return;
    }
    for(int i = pos; i<K; i++){
        if(visited[i] == true) continue;
            visited[i] = true;
            cases.push_back(arr[i]);
            getAllCases(i + 1, cnt + 1);
            cases.pop_back();
            visited[i] = false;
    }
}

int main(){
    int state = 0;
    while(1){
        cin >> K;
        v.clear();
        cases.clear();
        memset(visited, 0, sizeof(visited));

        if(K == 0) return 0;
        
        for(int i=0; i<K; i++){
            cin >> arr[i];
        }
        if(state != 0) cout<<"\n";
        state = 1;
        getAllCases(0, 0);
        
    }
    return 0;
}

