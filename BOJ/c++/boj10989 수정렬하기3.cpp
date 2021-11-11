#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    int arr[10010]={};
    for(int i=0, u; i<n; i++){
        cin >> u;
        arr[u]++;
    }
    
    for(int i=0; i<10010; i++){
        if(arr[i] != 0){
            for(int j=0; j<arr[i]; j++){
                cout << i<<"\n";
            }
        }
    }
    return 0;
}
