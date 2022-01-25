#include <iostream>
using namespace std;
int N, M, arr[10000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin>> arr[i];
    
    int ret = 0, sum = 0, lo = 0, hi = 0;
    while(1){
        if(sum >= M) sum -= arr[lo++];
        else if(hi == N) break;
        else sum += arr[hi++];
        if(sum == M) ret++;
    }
    cout<<ret<<"\n";
    return 0;
}
