#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool isOverlap(string word, vector<string>v, int curr){
    int idx=0;
    for(int i=curr+1;i<v.size();i++){
        if(v[i]==word) {idx=i; return true;}
    }
    return false;
}
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int idx=0;
    for(int i=0; i<words.size()-1; i++){
        int lastWordIndex = words[i].size()-1;
        if(words[i][lastWordIndex] != words[i+1][0] ) {idx = i+2;
            break;}
    }
    for(int i=0;i<words.size();i++){
      for(int j=i+1;j<words.size();j++){
          if(words[i]==words[j]) {
              idx = j+1;
              break;
          }
      }
    }

    if(idx == 0 ) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        if(idx%n==0) {
            answer.push_back(n);
            answer.push_back(idx/n);
        }
            
        else {
            answer.push_back(idx%n);
            answer.push_back(idx/n+1);
        }
    }
    
    cout << "Hello Cpp" << endl;
    return answer;
}
