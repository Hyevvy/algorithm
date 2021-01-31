#include <iostream>
using namespace std;
int countZero(int n){
    int count=0;
    for(int i=n; i>0; i=i/10){
        if(i%10==0) {
            //cout<<"i 일때 "<< i<< "count "<<count<<"\n";
            count++;}
    }
    return count;
}
int main(){
    int result =0;
    int tc, N, M;
    cin>>tc;
    for(int i=0; i<tc; i++){
        cin>>N>>M;
        if(N==0) result++;
        for(int i=N; i<=M; i++){
            result += countZero(i);
        }
        cout<<result<<"\n";
        result = 0;
    }
    return 0;
}

