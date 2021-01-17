#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    cin>>s;
    int result=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='Z'||s[i]=='S'||s[i]=='V'||s[i]=='Y') {
            result+=(s[i]-'A')/3 +2;
            continue;
       }
        result += (s[i]-'A')/3 +3;
    }
    cout<<result;
    return 0;
}

