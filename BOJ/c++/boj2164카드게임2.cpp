#include <iostream>
#include <queue>
using namespace std;
int main(){
    int N;
    cin>> N;
    queue<int> q;
    for(int i=1; i<=N; i++) {
        q.push(i);
    }
    
    while(q.size()!=1){
        q.pop();
        int top = q.front();
        q.pop();
        q.push(top);
    }
    cout<<q.front();
    return 0;
}

