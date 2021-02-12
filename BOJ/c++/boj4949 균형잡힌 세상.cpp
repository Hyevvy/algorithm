#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string a){
    stack<char> c;
    for(int i=0; i<a.size(); i++){
        if(a[i]=='(' || a[i]== '[') c.push(a[i]);
        else if(a[i]==')') {
            if(!c.empty() && c.top() == '(') c.pop();
            else return false;
        }
        else if(a[i]==']'){
            if(!c.empty() && c.top()=='[') c.pop();
            else return false;
        }
    }
    if(c.empty()) return true;
    return false;
}
int main(){
    while(1){
        string s;
        getline(cin,s);
        //cout<<s<<"\n";a
        if(s==".") break;
        if(isBalanced(s)) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}

