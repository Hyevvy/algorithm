#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool compare(pair<int, int>& a, pair<int,int>& b){
    if(a.second == b.second) return a.first<b.first;
    else return a.second<b.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc, first, second;;
    cin>>tc;
    vector<pair<int,int>> v;
    for(int i=0; i<tc; i++){
        cin>>first>>second;
        v.push_back(make_pair(first, second));
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<< " "<<v[i].second<<"\n";
    }
    return 0;
}

