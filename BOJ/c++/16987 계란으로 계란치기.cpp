#include <iostream>
using namespace std;
int N, S[9], W[9];
int ret = -1e9;
void hit(int cnt){
    //cnt : 현재 들고 있는 계란의 위치
    if(cnt >= N) {
        int ans = 0;
        for(int i=0; i<N; i++){
            if(S[i] <= 0) ans++;
        }
        ret = max(ret, ans);
        return;
    }
    if(S[cnt] <= 0) hit(cnt+1);
    else {
        bool flag = false;
            for(int j=0; j<N; j++){
                if(j==cnt || S[cnt] <= 0) continue;
                if(S[j] > 0 && S[cnt] > 0) {
                    S[j]-=W[cnt];
                    S[cnt]-=W[j];
                    flag = true;
                    hit(cnt + 1);
                    S[j]+=W[cnt];
                    S[cnt]+=W[j];
                }
            }
        if(!flag) hit(N);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> S[i] >> W[i];
    }
    hit(0);
    cout<<ret<<"\n";
    return 0;
}
