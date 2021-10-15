#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string num; //입력받는 숫자
    vector<int> eachNum; //각 자릿수를 저장
    bool haveZero = false; //0이 있는지
    int checkSum = 0; //합이 3의 배수인지
    
    cin >> num;
    
    //TODO : 30의 배수는 3의 배수이면서 일의 자리가 0
    for(int i=0; i<num.size(); i++){
        int temp = num[i] - '0';
        eachNum.push_back(temp);
        if(temp == 0) haveZero = true;
        checkSum += temp;
    }
    
    
    if(checkSum % 3 !=0 || haveZero == false) cout << "-1\n";
    else {
        //30의 배수 중 가장 큰 값 출력해야 함
        //생각한 방법 1 : 30의 배수를 다 돌면서 매번 각 자릿수가 다 있는지 확인하기
        //생각한 방법 2 : 각 자릿수들을 조합해서 30의 배수가 될 수 있게 (일의 자리는 0을 고정하나 값이 워낙 많이 나올 것 같음)
        sort(eachNum.begin(), eachNum.end());
        reverse(eachNum.begin(), eachNum.end());
        for(auto curr : eachNum){
            cout << curr;
        }
    }
    return 0;
}

