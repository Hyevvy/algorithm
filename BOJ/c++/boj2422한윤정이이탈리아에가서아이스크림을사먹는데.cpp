#include <iostream>
using namespace std;
int main(){
    int N, M; //아이스크림 종류, 섞어먹으면 안 되는 조합의 수
    cin>> N>> M;
    int arr[201][201] ={0};//처음엔 다 0으로
    int a, b;
    for(int i=0; i<M; i++){
        cin>>a>>b;
        arr[a-1][b-1]=1;
        arr[b-1][a-1]=1;
    }
    int count=0;
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(arr[i][j]==0 && arr[i][k]==0&& arr[j][k]==0) {
                   // cout<<"현재 "<<i+1<<" "<<j+1<<" " <<k+1 <<endl;
                    count++;}
            }
        }
    }
    cout<<count;
    return 0;
}

