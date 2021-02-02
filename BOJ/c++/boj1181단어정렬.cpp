#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> v;
bool isThere(string temp){
    for(int i=0; i<v.size(); i++){
        if(v[i]==temp) {return true;}
    }
    return false;
}

bool compare(string a, string b){
    if(a.size()==b.size()){
        return a < b;
    } else {
        return a.size() < b.size();
    }
}

int main(){
    int tc;
    cin>>tc;
    string temp;
    for(int i=0; i<tc; i++){
        cin>>temp;
        if(!isThere(temp)) v.push_back(temp);
    }
    sort(v.begin(),v.end(), compare);
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}
