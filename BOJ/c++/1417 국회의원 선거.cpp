#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<int> pq;
int N, dasom, tmp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> dasom;
    for(int i=1; i<N; i++){
        cin >> tmp;
        pq.push(tmp);
    }
    
    int cnt = 0;
    
    if(!pq.empty()){
        while(dasom <= pq.top()){
            int tp = pq.top();
            pq.pop();
            dasom++;
            tp--;
            cnt++;
            pq.push(tp);
        }
      
        cout<<cnt<<"\n";
    }
    else cout<<"0\n";
    return 0;
}
