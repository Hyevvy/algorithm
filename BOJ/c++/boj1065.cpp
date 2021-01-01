#include <iostream>
#include <vector>
using namespace std;
bool checkHan(int curr){
    vector<int> digit;
    for(int i=curr; i>0; i=i/10){
        digit.push_back(i%10);}
    int sub = digit[0] - digit[1];
    for(int i=1;i<digit.size()-1;i++){
        if(digit[i]-digit[i+1]!=sub) return false;
    }
    
    return true;
}
int main(){
    int N;
    cin >> N;
    int hanNum=0;
    N > 9 ? hanNum+=9 : hanNum += N; //한 자리수는 전부 한수
    for(int i=10;i<=N;i++){
        if(checkHan(i)) hanNum++;
    }
    cout<<hanNum;
    return 0;
}

