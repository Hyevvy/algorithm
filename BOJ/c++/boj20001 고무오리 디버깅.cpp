#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s, st;
    stack<int> result;
    while(1){
        getline(cin,s);
        if(s=="고무오리 디버깅 끝") {
            if(result.empty()) cout<<"고무오리야 사랑해\n";
            else cout<<"힝구\n";
            break;
        }
        if(s=="문제") result.push(1);
        else if(s=="고무오리") {
            if(result.empty()){
                result.push(1);
                result.push(1);
            }
            else result.pop();
        }
    }
    return 0;
}

