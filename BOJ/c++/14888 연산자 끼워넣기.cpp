#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[15], op[4];
int minVal = 1e9;
int maxVal = -1e9;
vector<int> v;
vector<int> ops; //값: 기호
bool visited[15];
void foo(int cnt){
    if(cnt==N-1){
        int ret = arr[0];
        for(int i=0; i<N-1; i++){
            int curr = v[i];
            if(curr == 0){
                ret += arr[i+1];
            }
            else if(curr == 1) {
                ret -= arr[i+1];
            }
            else if(curr == 2){
                ret *= arr[i+1];
            }
            else {
                if(ret < 0){
                    int tmp = abs(ret) / arr[i+1];
                    ret = -tmp;
                }
                else ret = ret / arr[i+1];
            }
        }
        if(ret > maxVal) {
            maxVal = ret;
        }
        if(ret < minVal){
            minVal = ret;
        }
    }
    
    for(int i=0; i<N-1; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(ops[i]);
            foo(cnt+1);
            visited[i] = false;
            v.pop_back();
        }
    }
}


int main(){
    int tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }
    
    for(int i=0; i<4; i++){
        if(op[i]!=0){
            for(int j=0; j<op[i]; j++){
                ops.push_back(i);
            }
        }
    }
    foo(0);
    
    cout << maxVal<<"\n"<<minVal<<"\n";
    return 0;
}
