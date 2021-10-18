#include <iostream>
#include <map>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    
    map<string, string> mp;
    for(int i=0; i<n; i++){
        string a, b;
        cin >> a >> b;
        mp.insert({a,b});
    }
    for(int i=0; i<m; i++){
        string target;
        cin>> target;
        cout<<mp[target]<<"\n";
    }
    return 0;
}
