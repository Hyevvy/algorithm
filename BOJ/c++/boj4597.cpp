#include <iostream>
#include <string>
using namespace std;
bool checkIsEven(string a){
    //1의 개수가 짝수이면 true return
    //1의 개수가 홀수이면 false return
    int checkOne=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='1') checkOne++;
    }
    if(checkOne%2==0) return true;
    else return false;
}
int main(){
    bool isEven;
    string inputString;
    while(1){
        cin>>inputString;
        if(inputString=="#") break;
    
        isEven=checkIsEven(inputString);
        if(inputString[inputString.size()-1]=='e'){
            //짝수패리티
            if(isEven) {
                inputString[inputString.size()-1]='0';
            } else {
                inputString[inputString.size()-1]='1';
            }
        }else {//홀수패리티
            if(isEven){
                inputString[inputString.size()-1]='1';
            }else {
                inputString[inputString.size()-1]='0';
            }
            
        }
        cout<<inputString<<"\n";
    }
}
