#include <iostream>
#include <stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    int result =0;

    stack<int> st;
    int state= 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            st.push('(');
            state=0;
        }
        if(state==0 && s[i]==')') {
            //이건 레이저
            st.pop();
            result += st.size();
            state=1;

        }
        else if(state==1 && s[i]==')'){
            //이건 파이프
            st.pop();
            result+=1;
        }
    }
    cout<<result;
    return 0;
}

