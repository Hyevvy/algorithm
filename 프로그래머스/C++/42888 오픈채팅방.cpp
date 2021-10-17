#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
vector<string> divide(string s){
    vector<string> res;
    string temp;
    for(int i=0; i<s.size(); i++){
        if(s[i]==' ') {
            res.push_back(temp);
            temp.clear();
        }
        else temp.push_back(s[i]);
    }
    res.push_back(temp);
    return res;
}
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mp;
    vector<vector<string>> all;
    for(auto curr: record){
        vector<string> v = divide(curr);
        //v[1] : uid , v[2] : nickName
        all.push_back(v);
        if(v[0]=="Enter"){
            if(mp.count(v[1]) > 0) mp[v[1]] = v[2];
            mp.insert({v[1], v[2]});
        }
        else if(v[0]=="Change") {
            if(mp.count(v[1]) > 0) {
                mp[v[1]] = v[2];
            }
            
        }
    }
    for(int i=0; i<all.size(); i++){
        if(all[i][0] == "Enter") answer.push_back(mp[all[i][1]]+"님이 들어왔습니다.");
        if(all[i][0] == "Leave") answer.push_back(mp[all[i][1]]+"님이 나갔습니다.");
    }
    
    return answer;
}
