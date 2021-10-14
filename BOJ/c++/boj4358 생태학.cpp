#include <iostream>
#include <map>
using namespace std;
int main(){
    cout<<fixed;
    cout.precision(4);
    string s;
    map<string, int> mp;
    int cnt = 0;
    while(getline(cin, s)){
        mp[s]++;
        cnt++;
    }

    for(auto curr : mp){
        cout<<curr.first <<" " << (double)curr.second / cnt * 100 <<"\n";
    }
    
    return 0;
}
