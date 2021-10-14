#include <iostream>
#include <set>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int nA, nB;
    cin >> nA >> nB;
    
    set<int> A;
    for(int i=0, num; i<nA; i++){
        cin >> num;
        A.insert(num);
    }
    

    for(int i=0, num; i<nB; i++){
        cin >> num;
        if(A.count(num) != 0) A.erase(num);
    }
    
    cout<< A.size()<<"\n";
    for(auto curr : A){
        cout << curr << " ";
    }
    return 0;
}
