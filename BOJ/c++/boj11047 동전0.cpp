#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(){
    int n;
    cin >> n;
  
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end());
    
    int ret = 0;
    int dep = 0;

    for(auto curr : v){
        dep += curr;
        ret += dep;
    }
    
    cout << ret <<"\n";
    return 0;
}
