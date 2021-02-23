#include <iostream>
using namespace std;
int main(){
    string inputS;
    cin>>inputS;
    for(int i=0; i<inputS.size(); i++){
        if(inputS[i]>='A' && inputS[i]<='Z') inputS[i]=inputS[i]+('a'-'A');
        else if(inputS[i]>='a' && inputS[i] <= 'z') inputS[i]=inputS[i]-('a'-'A');
    }
    cout<<inputS;
    return 0;
}

