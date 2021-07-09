#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char arr[101][101];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cin >> arr[i][j];
    }
    
    if( n==1 ) cout<<"0 0\n";
    else {
        int max_width = 0;
        int width = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[i][j]=='X'){
//                    cout<<i << " " << j <<" width : " << width <<"\n";
                    if(width >= 2) max_width++;
                    width = 0;
                }
                else {width++;}
            }
            if(width >= 2 ) max_width++;
            width = 0;
        }
        
        int max_height = 0;
        int height = 0;
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(arr[j][i]=='X'){
                    if(height>=2) max_height++;
                    height = 0;
                }
                else {height++;}
            }
            if(height>=2) max_height++;
            height = 0;
        }
    
    cout<<max_width <<" " <<max_height;
    }
    return 0;
}

