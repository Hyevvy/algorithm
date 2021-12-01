#include <iostream>
#include <map>
#include <vector>
using namespace std;
int N, K;
map<int, int> mp[7];
//idx : grade, key : gender, value : 해당 학생수
vector<int> v[6];
int main(){
    cin >> N >> K;
    int gender, grade;
    for(int i=0; i<N; i++){
        cin >> gender >> grade;
        mp[grade][gender]++;
    }
    
    int rooms = 0;
    for(int i=1; i<=6; i++){
        int girlsRoom = mp[i][0] / K;
        if(mp[i][0] % K != 0) girlsRoom++;
        
        int boysRoom = mp[i][1] / K;
        if(mp[i][1] % K != 0) boysRoom++;
        
        rooms = rooms + girlsRoom + boysRoom;
    }
    cout << rooms <<"\n";
    return 0;
}
