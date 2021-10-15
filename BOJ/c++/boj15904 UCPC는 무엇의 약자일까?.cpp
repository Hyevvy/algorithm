#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string v;
    for(int i=0; i<s.size(); i++){
        if(s[i] >='A' && s[i] <='Z') v.push_back(s[i]);
    }
   
    char ucpc[4] = {'U','C','P','C'};
    int idx = 0;
    for(auto curr : v){
        if(idx >= 4) break;
        if(curr == ucpc[idx]) idx++;
    }

    if(idx == 4) cout<<"I love UCPC\n";
    else cout<<"I hate UCPC\n";
}

