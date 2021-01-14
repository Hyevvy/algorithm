#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> v(8);
    vector<int> ascV{1,2,3,4,5,6,7,8};
    vector<int> descV{8,7,6,5,4,3,2,1};
    for(int i=0; i<8; i++){
        cin>>v[i];
    }
    if(ascV == v) cout<<"ascending";
    else if(descV == v) cout<<"descending";
    else cout<<"mixed";
    return 0;
}
