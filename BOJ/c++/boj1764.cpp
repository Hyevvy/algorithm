#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> didNotHear;
bool binarySearch(int low, int high, string name){
    if(low>high) return false;
    else {
        int mid = (low + high) / 2;
        if(didNotHear[mid] > name) return binarySearch(low, mid-1, name);
        else if(didNotHear[mid]<name) return binarySearch(mid+1, high, name);
        else return true;
    }
}
int main(){
    int N, M;
    cin>>N>>M;
    string name;
    vector<string> didNotSee(M);
    vector<string> didNotHs;
    for(int i=0;i<N;i++){
        cin>>name;
        didNotHear.push_back(name);
    }

    sort(didNotHear.begin(),didNotHear.end());
    for(int i=0;i<M;i++){
        cin>>didNotSee[i];
        if(binarySearch(0, N-1, didNotSee[i])) didNotHs.push_back(didNotSee[i]);
    }
    sort(didNotHs.begin(),didNotHs.end());
    cout<<didNotHs.size()<<"\n";
    for(int i=0;i<didNotHs.size();i++) cout<<didNotHs[i]<<"\n";
    return 0;
}

