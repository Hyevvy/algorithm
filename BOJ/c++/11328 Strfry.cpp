#include <iostream>
using namespace std;
bool isStrfry(string a, string b){
    int idx[1010] = {0,};
    int idxB[1010] = {0,};
    if(a.size() != b.size()) return false;
    for(int i=0; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(idx[i] == 0 && idxB[j] == 0){
                if(a[i] == b[j]) {
                    idx[i] = 1;
                    idxB[j] = 1;
                }
            }
        }
    }
    
    for(int i=0; i<a.size(); i++){
        if(idx[i] == 0) return false;
    }
    
    for(int i=0; i<b.size(); i++){
        if(idxB[i] == 0) return false;
    }
    return true;
}
int main(){
    int tc;
    cin >> tc;
    string a, b;
    for(int i=0; i<tc; i++){
        cin >> a >> b;
            
        isStrfry(a, b) == true ? cout <<"Possible\n" : cout <<"Impossible\n";
    }
    return 0;
}
