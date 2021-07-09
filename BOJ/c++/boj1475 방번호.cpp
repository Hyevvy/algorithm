#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(10);
    if(n==0) cout<<"1\n";
    else {
        for(int i=n; i>0; i=i/10){
            v[i%10]++;
        }
        
        int max = 0;
        for(int i=0; i<v.size(); i++){
            if(i== 6 || i== 9) continue;
            max < v[i] ? max = v[i] : max = max;
        }
        
        int sixNine = (v[6] + v[9]);
        sixNine % 2 == 0 ? sixNine /= 2 : sixNine = sixNine / 2 + 1;
        
        max < sixNine ? max = sixNine : max = max;
        cout<< max<<"\n";
    }
    return 0;
}

