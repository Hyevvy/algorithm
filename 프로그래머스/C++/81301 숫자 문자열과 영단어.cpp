#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<string> stringNum = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int getNum(string s){
   for(int i=0; i<stringNum.size(); i++){
       if(stringNum[i] == s) return i;
   }
    return -1;
}
int solution(string s) {
    int answer = 0;
    string ans = "";
    string numTemp = "";
    
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z'){
            numTemp.push_back(s[i]);
        }
        else{
            ans.push_back(s[i]);
        }
        if(!numTemp.empty()){
             int sn = getNum(numTemp);
            if(sn!=-1){
                ans+=to_string(sn);
                numTemp.clear();
            }
        }
    }
    
    answer = stoi(ans);
    return answer;
}
