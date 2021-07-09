#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    string s;
    cin >> s;
    
    stack<char> st;
    vector<int> v;
    int sum = 0;
    int state = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ')'){
            cout<<"1\n";
            if(!st.empty() && st.top() == '('){
                if(sum != 0) sum *=2;
                else sum += 2;
                st.pop();
                if(st.empty()) {v.push_back(sum); sum =0;}
            }
            else st.push(s[i]);
        }
        else if(s[i] == ']'){
            cout<<"2\n";
            if(!st.empty() && st.top() == '['){
                if(sum != 0) sum *=3;
                else sum+=3;
                st.pop();
                if(st.empty()) {v.push_back(sum); sum =0;}
            }
            else {
                state = 1; // 안에 다른거 안고 있는 경우 (곱하기 해야하
                st.push(s[i]);
            }
        }
        else {
            cout<<"3\n";
            st.push(s[i]);
        }
    }
    
    if(!st.empty()) cout<<"0\n";
    
    sum = 0;
    
    for(int i=0; i<v.size(); i++){
        cout<< "v[i] : " <<v[i]<<"\n";
        sum += v[i];
    }
    
    while(!st.empty()){
        cout<< st.top()<< " " ;
        st.pop();
    }
    
    cout<<sum<<"\n";
    return 0;
}

