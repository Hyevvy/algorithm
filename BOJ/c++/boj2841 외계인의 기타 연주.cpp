#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    int n, p; // 음의 수, 프랫 수
    cin >> n >> p;
    stack<int> v[7];
    
    int currN, currP;
    int ans = 0;
    for(int i=0; i<n; i++){
        cin >> currN >> currP;
        if(v[currN].empty()){
            //비어있으면 무조건 push
            v[currN].push(currP);
            ans++;
        }
        else{
            if(v[currN].top() < currP){
                //현재 음이 가장 높은 음일 경우
                v[currN].push(currP);
                ans++;
            }
            else if(v[currN].top() == currP) continue;
            else {
                //currP가 가장 높은 음일수 있게 pop하고 그 만큼 ans++
                    while(!v[currN].empty() && currP < v[currN].top()){
                        v[currN].pop();
                        ans++;
                    }
            
                if(!v[currN].empty() && v[currN].top() == currP) continue;
                v[currN].push(currP);
                ans++;
                }
            }
        
    }
    
    cout << ans;
    
    return 0;
}
