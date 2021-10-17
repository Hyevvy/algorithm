#include <iostream>
using namespace std;
int main(){
    int dp[51][51][51]{};
    int a, b, c;
    
    //TODO : basecase(바텀업!)
    for(int i=0; i<=50; i++){
        for(int j=0; j<=50; j++){
            for(int k=0; k<=50; k++){
                if(i==0 || j==0 || k==0) dp[i][j][k] = 1;
            }
        }
    }
    
    //TODO : dp 표 채우기
    for(int i=1; i<=20; i++){
        for(int j=1; j<=20; j++){
            for(int k=1; k<=20; k++){
                
                if(i < j && j < k)
                    dp[i][j][k] = dp[i][j][k-1] + dp[i][j-1][k-1] - dp[i][j-1][k];
                else dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k] + dp[i-1][j][k-1] - dp[i-1][j-1][k-1];
            }
                
        }
    }
    while(1){
        int res = 0;
        cin >> a >> b >> c;
        cin.ignore();
        if(a==-1 && b==-1 && c==-1) return 0;
        if(a<=0 || b<=0 || c<=0) res = 1;
        else if(a > 20 || b>20 || c>20){
            res = dp[20][20][20];
        }
        else res = dp[a][b][c];
//        else if(a < b && b < c){
//            dp[a][b][c] = dp[a][b][c-1] + dp[a][b-1][c-1] - dp[a][b-1][c];
//            res = dp[a][b][c];
//        }
//        else {dp[a][b][c] = dp[a-1][b][c] + dp[a-1][b-1][c] + dp[a-1][b][c-1] + dp[a-1][b-1][c-1];
//            res = dp[a][b][c];
//        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<res<<"\n";
    }
    return 0;
}

