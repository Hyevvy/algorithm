#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n; //막대기의 갯수
    cin >> n;
    
    vector<int> v(n,0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    int curr = v[v.size()-1]; // 맨 오른쪽애서 보이는 것(가장 높은)
    int result = 1; //보이는 막대기의 갯수
    for(int i=v.size()-2; i>=0; i--){
        if(v[i] > curr) {
            result++;
            curr = v[i];
        }
    }
    
    cout << result;
    return 0;
}

