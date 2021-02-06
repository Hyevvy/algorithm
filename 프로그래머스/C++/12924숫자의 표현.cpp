#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool isFinn(int curr, int size){
    int sum = 0;
    for(int i=curr; i<=size; i++){
        sum+=i;
        if(sum>size) return false;
        if(sum==size) return true;
    }
    return false;
}

int solution(int n) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        answer += isFinn(i, n);
    }
    return answer;
}
