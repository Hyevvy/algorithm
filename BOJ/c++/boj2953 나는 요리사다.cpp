#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[5][5] = {0, };
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    int sumArr[5] = {0,};
    for(int i=0; i<5; i++){
        for(int j=0; j<4; j++){
            sumArr[i] += arr[i][j];
        }
    }
    
    int max = sumArr[0];
    int idx = 0;
    for(int i=1; i<5; i++){
        if(max < sumArr[i]) {
            max = sumArr[i];
            idx = i;
            
        }
    }
    cout << idx+1 << " " << max;
    return 0;
}

