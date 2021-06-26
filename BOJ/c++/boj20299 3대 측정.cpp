#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, k, l; //팀의 수, 팀원 합, 팀원 개인 점수 커트라인
    cin >> n >> k >> l;
    
    
    vector<int> result; //합격한 팀
    vector<int> curr(3,0); //현재 심사보는 팀의 세 명
    int resultTeam = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        int state = 0; // state : 0 개인 심사 합격 state : 1 개인 심사 불합격
        for(int i=0; i<3; i++){
            cin >> curr[i];
            if(curr[i] < l) {
                state = 1;
            }
            else sum += curr[i];
        }
        
        if(state == 0 && sum >= k) {
            for(int i=0; i<3; i++){
                result.push_back(curr[i]);
            }
            resultTeam++;
        }
        curr.clear();
    }
    
    cout<<resultTeam<<"\n";

    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}

