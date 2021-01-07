#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    string temp;
    vector<pair<int,string>> v(n);
    for(int i=0; i<n; i++){
        cin>>temp;
        v[i].first= temp.size();
        v[i].second=temp;
    }
    sort(v.begin(),v.end());
    cout<<"*********"<<endl;
    string curr="";
    for(int i=0; i<v.size(); i++){
        if(curr != v[i].second){
        cout<<v[i].second<<endl;
        }
        curr = v[i].second;
    }
    return 0;
}


