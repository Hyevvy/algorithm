#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> nums;
int N, M, arr[31][31];
int ans = 0;
void getThree(int pos, int cnt){
    if(cnt==3){
        int sum = 0;
        for(int i=0; i<N; i++){
            int maxVal = 0;
            for(int j=0; j<nums.size(); j++){
                maxVal = max(maxVal, arr[i][nums[j]]);
            }
            sum+=maxVal;
        }

        ans = max(ans, sum);
        return;
    }
    for(int i=pos; i<M; i++){
        nums.push_back(i);
        getThree(i+1, cnt+1);
        nums.pop_back();
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    
    getThree(0, 0);
    
    cout<< ans <<"\n";
    return 0;
}
