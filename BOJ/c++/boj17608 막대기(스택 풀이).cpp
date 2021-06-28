#include <iostream>
#include <stack>
using namespace std;
int main(){
    int n, curr;
    cin >> n;
    stack<int> st;
    
    for(int i=0; i<n; i++){
        cin >> curr;
        while(!st.empty() && curr >= st.top() )
        {
//            cout<<"현재 size: " <<st.size() <<"현재 curr : "<<curr <<" 현재 top: "<<st.top()<<"\n";
//
            st.pop();
//            cout<<"현재 size: "<< st.size() <<"\n";
        }
        st.push(curr);
    }
    
//    for(int i=0; i<st.size(); i++){
//        cout<< st.top();
//        st.pop();
//    }
    cout<<st.size();
    return 0;
}

