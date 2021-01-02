#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> pad1;
bool isThere(int left, int right, int target){
//있으면 true, 없으면 false
    if(left>right) return false;
    else {
        int mid = (left + right)/2;
        if(target < pad1[mid]) return isThere(left, mid-1, target);
        else if(target > pad1[mid]) return isThere(mid+1, right, target);
        else return true;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc, N, M, temp;
    cin>>tc;
    for(int j=0; j<tc; j++){
        cin >> N;
        for(int i=0;i<N;i++) {
            cin>>temp;
            pad1.push_back(temp);
        }
        sort(pad1.begin(),pad1.end());
        
        cin>>M;
        for(int i=0; i<M; i++){
            cin>>temp;
            if (binary_search(pad1.begin(), pad1.end(), temp)) cout << "1\n";
            else cout << "0\n";
            //if(isThere(0, N-1, temp)) cout<<1<<"\n";
            //else cout<<0<<"\n";
        }
        pad1.clear();
    }
    return 0;
}

