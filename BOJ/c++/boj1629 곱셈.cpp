#include <iostream>
using namespace std;
int A, B, C;
int divide(int n){
    if(n == 1) return A % C;
    int t = divide(n/2);
    int ret = 1LL * t * t % C;
    if(n%2!=0) return 1LL * ret * A % C;
    return ret;
}
int main(){
    cin >> A >> B >> C;
    int result = divide(B);
    cout << result;
}

