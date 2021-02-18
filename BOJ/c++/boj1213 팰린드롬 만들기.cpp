#include <algorithm>
#include <iostream>
using namespace std;
string getP(string a){
    int arr[26]={0,};
    char middle= '0';
    for(int i=0; i<a.size(); i++){
        arr[a[i]-'A']++;
    }
    
    int state =0;
    if(a.size()%2==0) {
        //짝수개면 다 짝수개여야만 팰린드롬
        for(int i=0; i<26; i++){
            if(arr[i]%2!=0)  return "I'm Sorry Hansoo";
        }
    }
    else {
        //홀수개이면 하나만 홀수개 나머지는 짝수개
        for(int i=0; i<26; i++){
            if(arr[i]%2!=0) { middle =i+'A'; state++;}
        }
        if(state>=2) return "I'm Sorry Hansoo";
    }
    string s;

    for(int i=0; i<26; i++){
        for(int j=0; j<arr[i]/2; j++)
        s.push_back('A'+i);
    }
    
    
    string temp;
    for(int i=0; i<s.size(); i++){
        temp.push_back(s[i]);
    }
    if(middle!='0') temp.push_back(middle);
    reverse(s.begin(), s.end());
    for(int i=0; i<s.size(); i++){
        temp.push_back(s[i]);
    }
    return temp;
}
int main(){
    string temp;
    cin>>temp;
    cout<<getP(temp);
    return 0;
}


