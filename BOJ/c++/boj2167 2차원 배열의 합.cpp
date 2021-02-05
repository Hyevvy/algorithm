#include <iostream>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[301][301]={0,};
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++)
        cin>>arr[i][j];
    }
    int k;
    cin>>k;

    int a, b, c, d; //(a,b)~ (c,d)
    for(int i=0; i<k; i++){
        int result =0;
        cin>>a>>b>>c>>d;
//        for(int j=b; j<=d; j++){
//            for(int l=a; l<=c; l++){
//                result += arr[l-1][j-1];
//            }
//        }
        for(int j=a; j<=c; j++){
            for(int l=b; l<=d; l++)
            result += arr[j-1][l-1];
        }
        cout<<result<<"\n";
    }
    
    return 0;}

