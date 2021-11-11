#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    priority_queue<int> pqM; //음수들을 저장, 내림차순
    priority_queue<int, vector<int>, greater<int>> pqP; //양수들을 저장, 오름차순
    for(int i=0, u; i<n; i++){
        cin >> u;
        if(u != 0){
            if(u > 0){
                pqP.push(u);
            }
            else pqM.push(u);
        }
        else {
            int ret =0;
            //u == 0
            if(pqM.empty() && pqP.empty()) {
                cout<<"0\n";
            }
            else {
                if(pqM.empty()){
                    ret = pqP.top();
                    pqP.pop();
                }
                else if(pqP.empty()){
                    ret = pqM.top();
                    pqM.pop();
                }
                else {
                    int tpM = abs(pqM.top());
                    int tpP = pqP.top();
                    if(tpM > tpP){
                        ret = tpP;
                        pqP.pop();
                    }
                    else{
                        ret = pqM.top();
                        pqM.pop();
                    }
                }
                cout << ret << "\n";
            }
        }
        
    }
    return 0;
}
