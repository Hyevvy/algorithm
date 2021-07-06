#include <iostream>
using namespace std;
int getChoose(int a, int b){
    if(a==b || b ==0) return 1;
    //선택할 게 없거나 a개중에 a개를 선택하는 경우는 경우의 수가 1가지
    return getChoose(a-1, b-1) + getChoose(a-1, b);
}
int main(){
    //이항계수 : 4C3이라고 가정하면
    //4C3 = 3C2 + 3C3 (원소 1을 선택했을 때 남은 세개 중에 2개를 고르는 경우 +
    //원소 1을 선택하지 않았을 때 남은 3개 중에 3개를 고르는 경우)
    int n, k;
    cin >> n >> k;
    cout << getChoose(n, k);
    return 0;
}

