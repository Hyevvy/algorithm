#include <iostream>
#include <string>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    cin.ignore();
    for(int i=0; i<tc; i++){
        string str, simon = "Simon says";
        
        getline(cin, str);
        if(str.find(simon) == string::npos)
            continue;
        else {
            for(int j=10; j<str.size(); j++){
                cout<<str[j];
            }
            cout<<"\n";
        }
        
    }
    return 0;
}
