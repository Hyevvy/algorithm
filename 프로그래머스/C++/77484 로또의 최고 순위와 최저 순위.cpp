#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    int sameThing = 0;
    int missThing = 0;
    for(auto l : lottos){
        if(l == 0) missThing++;
        for(auto w : win_nums){
            if(l == w) sameThing++;
        }
    }
    int first = 7 - (sameThing + missThing) <= 6 ? 7 - (sameThing + missThing) : 6;
    int second = 7 - sameThing <= 6 ? 7 - sameThing : 6;
    answer.push_back(first);
    answer.push_back(second);
    
    return answer;
}
