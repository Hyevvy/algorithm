#include <iostream>
#include <cstring>
using namespace std;
int dp[110][110];
int recur(int r, int c){
    if(c==0 || r==c) return 1;
    if(dp[r][c] != -1) return dp[r][c];
    return dp[r][c] = recur(r-1, c-1) + recur(r-1, c);
    
}
int main(){
    int n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << recur(n-1, k-1);
    return 0;
}
