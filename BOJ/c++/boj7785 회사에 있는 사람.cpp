#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    string name, el;
    set<string, greater<string>> st;
    for(int i=0; i<n; i++){
        cin >> name >> el;
        if(el=="enter") st.insert(name);
        else st.erase(name);
    }
   
    for(auto curr : st){
        cout<< curr << "\n";
    }
    return 0;
}
