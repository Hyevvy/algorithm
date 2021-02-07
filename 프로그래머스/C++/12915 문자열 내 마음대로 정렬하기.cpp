#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
bool compare(pair<string, char> a, pair<string, char>b){
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<string, char>> v;
    for(int i=0; i<strings.size(); i++){
        v.push_back(make_pair(strings[i], strings[i][n]));
    }
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
    }
    return answer;
}
