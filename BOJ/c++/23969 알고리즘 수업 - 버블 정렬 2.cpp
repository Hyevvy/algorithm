#include <iostream>
using namespace std;
int N, K, arr[10010];
void bubble_sort(){
    int cnt = 0;
    for(int i=N; i>=2; i--){
        for(int j=1; j<=N-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                cnt++;
                if(cnt == K){
                    for(int i=1; i<=N; i++){
                        cout << arr[i]<<" ";
                    }
                    cout<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"-1\n";
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> K;
    for(int i=1; i<=N; i++){
        cin>> arr[i];
    }
    bubble_sort();
    return 0;
}
