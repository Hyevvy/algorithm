#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    int va[100] = {0,};
    int vb[100] = {0,};
    
    int i = a;
    while(i > 1){
        for(int j = 2; j < a; j++){
            if( i % j == 0){
                i = i / j;
                va[j]++;
                break;
            }
        }
    }
    

    
    i = b;
    while(i > 1){
        for(int j = 2; j < b; j++){
            if( i % j == 0){
                i = i / j;
                vb[j]++;
                break;
            }
        }
    }
    

    //최대 공약수 확인
    int GCD = 1; //최대공약수
    int MCM = 1; //최소공배수
    for(int i=1; i<100; i++){
        if(va[i]!=0 && vb[i]!= 0)
        {
            GCD *= i;
        }
        if(va[i]!=0 || vb[i]!=0) {
            va[i] > vb[i] ? MCM *= pow(i, va[i]) : MCM *= pow(i, vb[i]);
        }
    
    }
    
    
    cout<<GCD<<"\n";
    cout<<MCM<<"\n";
    
    return 0;
}


