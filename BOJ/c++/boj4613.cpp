#include <iostream>
#include <vector>
using namespace std;
int quickSum(string a){
    int sum=0;
    for(int i=0;i<a.size();i++){
        if(a[i]==' ') continue;
        sum += (i+1) *((a[i]-'A')+1);
    }
    return sum;
}
int main(){
    string inputString;
    while(1){
        getline(cin,inputString);
        if(inputString=="#") break;
        cout<<quickSum(inputString)<<"\n";
        inputString.clear();
    }
    return 0;
}
