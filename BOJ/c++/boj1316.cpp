#include <iostream>
#include <vector>
using namespace std;
// 앞에 나온 단어가 다른 단어를 두고 또 나오는지 확인해야함.
bool checkGroupWord(string a){
    vector<char> memberChar;
    for(int i=0; i<a.size()-1; i++){
        memberChar.push_back(a[i]);
        if(a[i]==a[i+1]) continue;
        if(a[i]!=a[i+1]){
            for(int j=0;j<memberChar.size();j++){
                if(a[i+1]==memberChar[j] &&a[i]!=memberChar[j]){ //cout<<"a[i+1]는 "<<a[i+1]<<" memberchar[i]는 "<<memberChar[i];
                    return false;}
            }
        }
    }
    return true;
}
int main(){
    int tc, numGroupWord=0;
    string inputString;
    cin>>tc;
    for(int i = 0; i < tc; i++){
        cin>>inputString;
        if(checkGroupWord(inputString)) numGroupWord++;
    }
    cout<<numGroupWord;
    return 0;
}
