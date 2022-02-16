#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N, arr[100010];
int dp[100010];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int maxVal = dp[0] = arr[0];
    for(int i=1; i<N; i++){
        dp[i] = max(arr[i] , dp[i-1] + arr[i]);
        maxVal = max(maxVal, dp[i]);
    }

    cout<<maxVal;
    return 0;
}
