#include <iostream>
#include <stack>
using namespace std;
bool isGoodWord(string a){
    stack<char> s;
    s.push(a[0]);
        
    for(int i=1; i<a.size(); i++){
        if(!s.empty() && s.top()==a[i]) { s.pop();}
        else {s.push(a[i]);}
    }
    
    if(s.empty()) return true;
    else return false;
}
int main(){
    int n;
    cin>>n;
    string curr;
    int result=0;
    for(int i=0; i<n; i++){
        cin>>curr;
        if(isGoodWord(curr)) result++;
    }
    cout<<result;
    return 0;
}

