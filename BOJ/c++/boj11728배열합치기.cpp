#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, temp;
    cin>> n >> m;
    vector<int> result;
    for(int i=0; i<n; i++){
        cin>>temp;
        result.push_back(temp);
    }
    for(int i=0; i<m; i++){
        cin>>temp;
        result.push_back(temp);
    }
    sort(result.begin(),result.end());
    //result.erase(unique(result.begin(),result.end()),result.end());
    for(int i=0; i<result.size(); i++)
        cout<<result[i]<<" ";
    return 0;
}

