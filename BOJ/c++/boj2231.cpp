#include <iostream>
using namespace std;
int main(){
    int num, sum, part;
    cin>> num;
    for(int i=1; i<num; i++){
        sum=i;
        part=i;
        while(part){
            sum+=i;
            part/=10;
        }
        if(sum==num) {cout<<i<<"\n"; return 0;}
    }
    cout<<"0"<<"\n";
    return 0;
}
