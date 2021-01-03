#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(int m=0; m<commands.size(); m++){
        int i = commands[m][0]; //2 ,4 , 1
        int j = commands[m][1]; //5 , 4 , 7
        int k = commands[m][2]; //3, 1, 3
        for(int l = i-1; l<j; l++) {temp.push_back(array[l]); }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[k-1]);
        temp.clear();
    }
    return answer;
}
