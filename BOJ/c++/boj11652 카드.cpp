#include <iostream>
#include <map>
using namespace std;
int main(){
    long long num;
    int n;
    cin >> n;
    map<long long, int> mp;
    for(int i=0; i<n; i++){
        cin >> num;
        mp[num]++;
    }
    long long max = -1e9;
    long long idx = 0;
    for(auto ret : mp){
        if(ret.second > max) {
            max = ret.second;
            idx = ret.first;
        }
    }
    cout<<idx<<"\n";
}
