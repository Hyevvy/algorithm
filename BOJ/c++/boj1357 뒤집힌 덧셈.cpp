#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int getReverse(int a){
    int result=0;
    vector<int> resultV;
    for(int i=a; i>0; i=i/10){
        resultV.push_back(i%10);
    }
    reverse(resultV.begin(), resultV.end());
    for(int i=0; i<resultV.size(); i++){
        result += resultV[i] * pow(10,i);
    }
    return result;
}
int main(){
    int x, y;
    cin>> x>> y;
    cout<<getReverse(getReverse(x)+getReverse(y));
   
    return 0;
}

