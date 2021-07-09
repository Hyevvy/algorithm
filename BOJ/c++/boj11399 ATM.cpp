#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int currSum =0;
    vector<int> sums;
    for(int i = 0; i<v.size(); i++){
        currSum = 0;
        for(int j=0; j<=i; j++){
//                cout<<"i: "<< i<< " j: "<<j <<" sum : "<< sum<<"\n";
            currSum += v[j];
        }
        sum += currSum;
    }
    cout<< sum<<"\n";
    return 0;
}

