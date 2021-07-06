#include <iostream>
using namespace std;
int getRoomNumber(int h, int w, int n){
    int last = 1;
    int ans = 0;
    while(1){
        if(n <= h) {
            ans += 100 * n + last;
            return ans;
        }
        else {
            //n이 72이고 h가 30이면 72- 30 - 30 (last는 3이 됨)
            n = n - h;
            last++;
        }
    }
}
int main(){
    int tc, h, w, n;
    cin >> tc;
    for(int i=0; i<tc; i++){
        cin>> h>> w >> n;
        cout<<getRoomNumber(h, w, n)<<"\n";
    }
    return 0;
}

