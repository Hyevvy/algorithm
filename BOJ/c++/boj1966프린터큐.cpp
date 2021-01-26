#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;
bool comp(int a, int b){
    return a>b;
}
int getIdx(vector<int> v, int target){
    int result=0;
    queue<pair<int,int>> q; //first : value, second : index;
    for(int i=0; i<v.size(); i++){
        q.push(make_pair(v[i], i));
    }
    sort(v.begin(),v.end(), comp);
    int idx=0;
    while(!q.empty()){
        if(q.front().first == v[idx]){
            if(q.front().second == target){
                return (++result);
            }
            idx++;
            result++;
            q.pop();
        }
        else {
            pair<int, int> temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return result;
}
int main(){
    int tc;
    cin>>tc;
    int decSize, doc;
    for(int i=0; i<tc; i++){
        cin>>decSize>>doc;
        vector<int> v(decSize);
        for(int i=0; i<decSize; i++){
            cin>>v[i];
        }
        cout<<getIdx(v, doc)<<"\n";
        v.clear();
    }
    return 0;
}

