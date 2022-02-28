#include <iostream>
using namespace std;
int N, M;
bool bulbs[4002];
void f1(int idx, int state){
    bulbs[idx] = state;
}

void f2(int start, int end){
    for(int i=start; i<=end; i++){
        bulbs[i] =! bulbs[i];
    }
}

void f3(int start, int end){
    for(int i=start; i<=end; i++){
        bulbs[i] = false;
    }
}

void f4(int start, int end){
    for(int i=start; i<=end; i++){
        bulbs[i] = true;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> bulbs[i];
    }
    
    int order, a, b;
    for(int i=0; i<M; i++){
        cin >> order >> a >> b;
        if(order==1){
            f1(a, b);
        }
        else if(order == 2){
            f2(a,b);
        }
        else if(order == 3){
            f3(a, b);
        }
        else{
            f4(a,b);
        }
    }
    
    for(int i=1; i<=N; i++){
        cout << bulbs[i] << " ";
    }
    return 0;
}
