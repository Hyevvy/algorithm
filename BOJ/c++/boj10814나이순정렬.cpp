#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> u,  pair<int, int> v){
    if(u.first == v.first) return u.second < v.second;
    return u.first < v.first;
}
int main(){
    int tc;
    cin>>tc;
    int age;
    string name;
    vector<string> names(tc);
    vector<pair<int, int>> v(tc);
    for(int i=0; i<tc; i++){
        cin>>age>>name;
        names[i]=name;
        v[i]=make_pair(age, i);
    }
    
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<names[v[i].second]<<"\n";
    }
    return 0;
}

