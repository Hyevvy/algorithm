#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);// answer[0] : 몇번 턴이 돌았는지, answer[1]:제거된 0의 개수
    string temp;
    int length =0;
    while(1){
        if(s.size()==1) break;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0') {
                answer[1]++;//제거된 0의 개수 증가시키기
                continue;
            }
            else length++;
        }
        s.clear(); //size도 0이 된다
        for(int i=length; i>0; i=i/2){
            s.push_back(i%2+'0');
        }
        length =0;
        
        answer[0]++; //한 턴이 돌았다는 의미
    }
    return answer;
}
