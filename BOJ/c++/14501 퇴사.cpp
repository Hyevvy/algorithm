#include <iostream>
using namespace std;
int N;
int t[20];
int p[20];
int maxProfit = 0;
void getMax(int idx, int profit ){
    if (idx >= N + 1){
        if(maxProfit < profit){
            maxProfit = profit;
        }
        return;
    }
    if(idx + t[idx] <= N + 1) getMax(idx+t[idx], profit+p[idx]);
    getMax(idx+1, profit);
}
int main(){
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> t[i];
        cin >> p[i];
    }
    getMax(1, 0);
    
    cout<<maxProfit<<"\n";
    return 0;
}
s
