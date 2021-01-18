#include <string>
using namespace std;
string solution(string s){
    for(int i=0; i<s.size(); i++){
        for(int j=0; j<s.size()-i; j++){
            if(s[j]<s[j+1]) {
                int temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    string answer= s;
    return answer;
}
