#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int getLength(vector<char> v){
    int length = 10;
    char curr = v[0];
    for(int i=1; i<v.size(); i++){
        if(curr != v[i]) {
            length += 10;
            curr = v[i];
        }
        else length += 5;
    }
    return length;
}
int main(){
    string inputS = "";
    vector<char> bowl;
    getline(cin, inputS);
   
    for(int i=0; i<inputS.size(); i++){
        if(inputS[i] == '(' || inputS[i] == ')' ) bowl.push_back(inputS[i]);
    }
    cout<<getLength(bowl);
    
}

