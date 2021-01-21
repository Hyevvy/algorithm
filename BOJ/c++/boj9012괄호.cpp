#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool isVps(string a){
    vector<char> myStack;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='(') myStack.push_back('(');
        else if(a[i]==')') {
            if(myStack.empty()) return false;
            myStack.pop_back();
        }
    }
    if(!myStack.empty()) return false;
    return true;
}
int main(){
    int tc;
    cin>>tc;
    string temp;
    for(int i=0; i<tc; i++){
        cin>>temp;
        if(isVps(temp)) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}

