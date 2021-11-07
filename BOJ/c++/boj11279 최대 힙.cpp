#include <iostream>
#include <map>
#include <queue>
using namespace std;
int n;
priority_queue<int> pq;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i=0, u; i<n; i++){
        cin >> u;
        
        if(u == 0){
            if(pq.empty()){
                cout << "0\n";
            }
            else {
                cout << pq.top() <<"\n";
                pq.pop();
            }
        }
        else pq.push(u);
        
    }
    return 0;
}
