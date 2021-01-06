#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector<int> snacks;
int main(){
    string s;
    cin>>s;
    vector<string> tail(s.length());
    for(int i=0;i<s.size();i++){
        for(int j=s.size()-1;j>=i;j--){
            tail[i].push_back(s[j]);
        }
        reverse(tail[i].begin(),tail[i].end());
    }
    sort(tail.begin(),tail.end());
    
    for(int i=0;i<tail.size();i++)
    cout<<tail[i]<<"\n";
    return 0;
}

