#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N;
char arr[10][10];
vector<string> cases;
void getCase(int count, pair<int, int> prevPos, string thisCase){
    if(thisCase.size() == 2 * N - 1){
        //cout << thisCase <<" \n";
        cases.push_back(thisCase);
        thisCase.pop_back();
        return;
    }
    if(prevPos.first < N && prevPos.second < N){
        getCase(count+1, {prevPos.first+1, prevPos.second}, thisCase + arr[prevPos.first][prevPos.second]);
        getCase(count+1, {prevPos.first, prevPos.second+1}, thisCase + arr[prevPos.first][prevPos.second]);
    }
}
int getSum(string str){
    int ret = str[0] - '0';
    int strSize = str.size();
    
    for(int i=1 ,idx = 0; i<strSize-1; i=i+2, idx++){
        int num = str[i+1] -'0';
        if(str[i] == '+'){
            ret = ret + num;
        }
        else if(str[i] == '-'){
            ret = ret - num;
        }
        else if(str[i] == '*'){
            ret = ret * num;
        }
    }

    return ret;
}
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
        cin >> arr[i][j];
    }
    
    getCase(0, {0,0}, "");
    int minValue = 1e9;
    int maxValue = -1e9;
    for(auto curr : cases){
        int ret = getSum(curr);
        minValue = min(minValue, ret);
        maxValue = max(maxValue, ret);
    }
    
    cout << maxValue << " " <<minValue <<"\n";
    return 0;
}
