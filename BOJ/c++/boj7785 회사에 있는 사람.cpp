#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    map<string, int>mp; //name , 1: true 0:false
    int tc;
    cin>> tc;
    string name, el;
    vector<string> here;
    for(int i=0; i<tc; i++){
        cin >> name >> el;
        if(el=="enter") mp.insert({name, 1});
        else mp.erase(name);
    }
    vector<string> v;
    for(auto curr : mp)
        if(curr.second == 1)
            v.push_back(curr.first);
    
    reverse(v.begin(), v.end());
    for(auto curr : v){
        cout<< curr <<"\n";
    }
    
    return 0;
}

