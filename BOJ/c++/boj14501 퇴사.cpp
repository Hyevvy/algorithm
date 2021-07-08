#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, t, p;
    cin >> n;
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        cin >> t >> p;
        v.push_back(make_pair(t, p));
    }
    
    int rest = 0; //쉬어야 하는 타임 (1일차에 3일짜리 상담 받으면 2일 쉬어야함)
    int max = 0;
    
    for(int j=0; j<n; j++){
        int money = 0;
        for(int i=j; i<n; i++){
            if(rest!=0) {
                rest--;
                continue;
            }
            else{
                if(v[i].first - 1 >= n - i) continue;
                rest = v[i].first-1;
                money += v[i].second;
            }
        }
        money > max ? max = money : max = max;
    }
    
    cout<< max;
    return 0;
}

