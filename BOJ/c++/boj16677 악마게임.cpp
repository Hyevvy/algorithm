#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string gbs;
int ssa[101];
string s;
int isIncluded(){
    int res = 0;
    for(int i=0; i<gbs.size(); i++){
        for(int j=0; j<s.size(); j++){
            if(gbs[i] == s[j]) {
                s[j] = s[j] + ('a' - 'A'); //소문자로 변경하기
                res++;
                break;
            }
            
        }
    }
    //남은 글자수
    if(res == gbs.size()) return s.size()-res;
    return -1;
}
int main(){
    cin >> gbs;
    int tc, G;
    cin >> tc;
    double temp;
    vector<pair<string, double>> strV;
    for(int i=0; i<tc; i++){
        cin >> s >> G;
        int res = isIncluded();
        if(res == -1) continue;
        temp = (double) G / res;
        strV.push_back({s, temp});
    }
    string ans;
    double max = 0; // 가성비 최댓값
    int idx = 0; // 인덱스
    
    //갑분싸단어가 다 들어가있는지 확인하기 위해 소문자로 바꿨던 각 string들을
    //다시 대문자로 바꿔준다.
    for(int i=0; i<strV.size(); i++){
        transform(strV[i].first.begin(), strV[i].first.end(), strV[i].first.begin(), ::toupper);
    }
    
    for(int i=0; i<strV.size(); i++){
        if(max < strV[i].second) {
            //가중치를 비교해 갱신하고
            //가중치 str의 인덱스를 갱신함.
            max = strV[i].second;
            idx = i;
        }
    }
    if(max == 0) cout<<"No Jam\n";
    else cout<<strV[idx].first<<"\n";
    return 0;
}
