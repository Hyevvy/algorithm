#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void getReverse(string s, int idx){
    stack<char> st;
    deque<char> ans;

    for(int i=0; i <s.size() ; i++){
        st.push(s[i]);
        if(s[i]== ' ' || i == s.size() - 1 ){
            if(i==s.size()-1) ans.push_front(' ');
            while(!st.empty()){
                ans.push_front(st.top());
                st.pop();
            }
            
        }
    }
    
    cout<<"Case #"<< idx <<": ";
    while(!ans.empty()){
        cout<<ans.front();
        ans.pop_front();
    }
    cout<<"\n";
}


int main(){
    int n;
    cin >> n;
    string inputS;
    cin.ignore();
    
    for(int i=0; i<n; i++){
        getline(cin, inputS);
        getReverse(inputS, i+1);
    }
    return 0;
}

