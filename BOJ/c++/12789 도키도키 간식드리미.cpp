#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int N;
int main(){
    int tmp;
    queue<int> q;
    stack<int> st;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        q.push(tmp);
    }
    
    int curr = 1; // curr == N 이면 Nice
    while(!q.empty()){
        int tp = q.front();
        if(tp == curr) {
            curr++;
            q.pop();
        } else if(!st.empty() && st.top() == curr){
            curr++;
            st.pop();
        }
        else {
            st.push(q.front());
            q.pop();
        }
    }
    
    while(!st.empty()){
        int tp = st.top();
        st.pop();
        if(tp == curr) curr++;
        else break;
    }
    if(curr == N+1) cout <<"Nice\n";
    else cout <<"Sad\n";
    return 0;
}
