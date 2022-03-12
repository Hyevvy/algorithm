#include <iostream>
using namespace std;
long long A, B, ret = 1e9;
void dfs(long long currNum, long long cnt){
    if(currNum > B) return;
    if(currNum == B){
        ret = min(ret, cnt);
        return;
    }
    dfs(currNum * 10 + 1 , cnt + 1);
    dfs(currNum * 2 , cnt + 1);
}
int main(){
    cin >> A >> B;
    dfs(A, 1);
    if(ret == 1e9) cout <<"-1\n";
    else cout<<ret<<"\n";
    
    return 0;
}
