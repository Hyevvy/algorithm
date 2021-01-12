#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    for(int i=n; i>0; i=i/3){
        v.push_back(i%3);
    }

    for(int i=0; i<v.size(); i++){
        answer += v[i]* pow(3,v.size()-i-1);
    }
    return answer;
}
