#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> digitToBinary(int digit, int n){
    int idx = 0;
    vector<int> result;
    vector<int> temp;
    for(int i=digit; i>0; i=i/2){
        temp.push_back(i%2);
    }
    reverse(temp.begin(),temp.end()); //30이 01111로 들어가서 뒤집어주는 함수
    for(int j=0; j<n-temp.size(); j++)
        result.push_back(0); // 9가 1001 인데 01001이어야하므로 앞에다가 0을 넣어주는 부분
    for(int i=0; i<temp.size(); i++) result.push_back(temp[i]);
    return result;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    vector<int> firstVec, secondVec;
    int idx=0;
    for(int i=0; i<n; i++){
        firstVec= digitToBinary(arr1[i], n);// 01001
        secondVec = digitToBinary(arr2[i], n); // 11110
        for(int j=0; j<n; j++){
            if(firstVec[j] == 1 || secondVec[j] == 1) answer[i].push_back('#');
            else answer[i].push_back(' ');
        }
    }
    return answer;
}
