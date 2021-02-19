#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<pair<int, string>> v;
bool isThere(string s){
    for(int i=0; i<v.size(); i++){
        if(v[i].second==s) {
            v[i].first++;
            return true;
        }
    }
    return false;
}
bool compare(pair<int, string> a, pair<int, string> b){
    if(a.first > b.first) return true;
    else if(a.first==b.first) return (a.second<b.second);
    else return false;
}
int main(){
    int n;
    cin>>n;
    string temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        if(isThere(temp)==false){
            v.push_back(make_pair(1, temp));
        }
    }
    int idx=0;
    int max = 0;
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<v.size(); i++) {
        if(v[i].first>max) {max = v[i].first; idx =i;}
    }
    cout<<v[idx].second;
    return 0;
}

