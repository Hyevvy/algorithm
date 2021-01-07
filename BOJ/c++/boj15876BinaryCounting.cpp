#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    vector<int> binaryV;
    vector<int> currentBinary;
    binaryV.push_back(0);
    for(int i=0;binaryV.size() < n*5;i++){
        for(int j=i; j>0; j=j/2){
            currentBinary.push_back(j%2);
        }
        reverse(currentBinary.begin(),currentBinary.end());
        binaryV.insert(binaryV.end(),currentBinary.begin(),currentBinary.end());
        currentBinary.clear();
    }
    int count =0;
    for(int i=0;i<binaryV.size() && count<5;i++){
        if(i%n + 1 == k) {
            cout<<binaryV[i]<<" ";
            count++;}
    }
    return 0;
}

