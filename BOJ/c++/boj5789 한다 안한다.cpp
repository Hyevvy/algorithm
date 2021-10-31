#include <iostream>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        string s;
        cin >> s;
        int sSize = s.size();
        bool isOk = false;
        if(s[sSize/2-1] == s[sSize/2]) cout<<"Do-it\n";
        else cout<<"Do-it-Not\n";
    }
    return 0;
}
