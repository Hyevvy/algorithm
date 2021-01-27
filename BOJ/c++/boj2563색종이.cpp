#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count=0;
    int x, y;
    int arr[100][100]={0};
    for(int i=0; i<n; i++){
        cin>>x>>y;
        for(int j=x; j<x+10; j++){
            for(int k=y; k<y+10; k++)
             arr[j][k]=1; //3,4 arr[3][4]=1;
        }
    }
    for(int i=0;i<100; i++){
        for(int k=0; k<100; k++)
        if(arr[i][k]==1) count++;
    }
    cout<<count;
    return 0;
}

