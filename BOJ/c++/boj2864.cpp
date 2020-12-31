#include <iostream>
using namespace std;
int main(){
    string num1, num2;
    string maxNum1, maxNum2;
    string minNum1, minNum2;
    cin>>num1>>num2;
    for(int i=0;i<num1.size();i++){
        if(num1[i]=='5' || num1[i]=='6' ) {maxNum1[i]='6'; minNum1[i]='5';}
        else {maxNum1[i]=num1[i]; minNum1[i]=num1[i];}
    }
    for(int i=0;i<num2.size();i++){
        if(num2[i]=='5' || num2[i]=='6' ) {maxNum2[i]='6'; minNum2[i]='5';}
        else {maxNum2[i]=num2[i]; minNum2[i]=num2[i];}
    }
    int max=stoi(maxNum1) + stoi(maxNum2);
    int min= stoi(minNum1) + stoi(minNum2);
    cout<< min <<" "<<max<<"\n";
    return 0;
}
