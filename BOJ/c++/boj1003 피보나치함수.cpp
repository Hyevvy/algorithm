#include <iostream>
#include <cstring>
using namespace std;
int dp[110][2];
//dp[n][0] : n일때 0이 호출된 횟수
//dp[n][1] : n일때 1이 호출된 횟수

int main(){
    int T, num;
    cin >> T;
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    for(int i=0; i<T; i++){
        cin >> num;
        for(int j=2; j<=num; j++){
            dp[j][0] = dp[j-1][0] + dp[j-2][0];
            dp[j][1] = dp[j-1][1] + dp[j-2][1];
        }
        cout<<dp[num][0] << " " <<dp[num][1]<<"\n";
    }
    
    return 0;
}

