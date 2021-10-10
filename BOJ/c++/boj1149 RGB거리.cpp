#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[1010][3];
int dp[1010][3]; // r : curr floor , c : curr r , g ,b
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin >> arr[i][j];
    }

    for(int i=0; i<3; i++){
        dp[0][i] = arr[0][i];
    }

    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }

    int min = 1e9;
    
    for(int i=0; i<3; i++){
        if(min > dp[n-1][i]) min = dp[n-1][i];
    }
    
    cout << min;
    return 0;
}
