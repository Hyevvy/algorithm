#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    string temp;
    for(int i=0; i<tc; i++){
        cin>>temp;
        cout<<temp[0]+temp[2]-'0'-'0'<<endl;
    }
    return 0;
}

