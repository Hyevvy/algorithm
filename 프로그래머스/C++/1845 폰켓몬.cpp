#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int choiceNum = nums.size() / 2;
    map<int, int> mp; //key : 폰켓몬 번호, value : 폰켓몬 갯수
    
    for(auto curr : nums){
        mp[curr]++;
    }
    
    int idx = 0;
    for(auto curr : mp){
        if(idx >= choiceNum) break;
        if(curr.second != 0){
            idx++;
            answer++;
        }
    }

    return answer;
}
