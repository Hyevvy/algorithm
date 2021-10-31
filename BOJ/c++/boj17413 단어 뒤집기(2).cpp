#include <iostream>
using namespace std;
string stringFlip(string s){
    string temp;
    for(int i=s.size()-1; i>=0; i--){
        temp.push_back(s[i]);
    }
    return temp;
}
int main(){
    string s, tag, flip;
    getline(cin,s);
    bool isFlipPrint = false;
    bool isTag = false;
    int sSize = s.size();
    for(int i=0; i<sSize; i++){
        if(s[i] == '<'){
            isTag = true;
            isFlipPrint = true;
        }
        else if(s[i] == '>') {
            tag.push_back(s[i]);
            cout << tag;
            tag.clear();
            isTag = false;

            continue;
        }
        if(isTag) tag.push_back(s[i]);
        else{
            if(s[i]!=' ')
            flip.push_back(s[i]);
        }
        if(isFlipPrint || s[i] == ' ' || i==sSize-1){
            cout<<stringFlip(flip);
            flip.clear();
            isFlipPrint = false;
        }
        if(!isTag && s[i]==' ') cout<<s[i];
    }
//    cout<<tag<<"\n";
//    cout<<flip<<"\n";
    return 0;
}
