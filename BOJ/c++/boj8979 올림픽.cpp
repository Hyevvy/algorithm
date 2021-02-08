#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
bool compare(vector<int> a, vector<int> b){
    if(a[1] == b[1]){
        if(a[2]==b[2]){
            return a[3] > b[3];
        }
        return a[2] > b[2];
    }
    return a[1] > b[1];
}
int main(){
    int n, k;
    cin>>n>>k;
    vector<vector<int>> v;
    int a,b,c,d;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c>>d;
        v.push_back( {a,b,c,d});
    }
    sort(v.begin(), v.end(), compare);
    int idx=0;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i][0]==k) idx=i;
    }
    cout<<idx<<"\n";
    return 0;
}
