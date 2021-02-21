#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<pair<int, int>> v; //first: 몸무게, second: 키
int getReward(int idx){
    int dungchi=1;
    int weight = v[idx].first;
    int height = v[idx].second;
    for(int i=0; i<v.size(); i++){
        if(i==idx) continue;
        if(weight < v[i].first && height < v[i].second) dungchi++;
    }
    return dungchi;
}
int main(){
    int n;
    cin>>n;
    int a, b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    for(int i=0; i<n; i++){
        cout<<getReward(i)<<" ";
    }
    return 0;
}

