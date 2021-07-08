#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    
    int sum = 0;
    vector<int> v;
    int digit = 0; //자릿수 확인용
    for(int i=n; i>0; i=i/10){
        sum += i%10;
        v.push_back(i % 10);
        digit++;
    }
    sort(v.begin(), v.end());
    
    int mircoNum = 0;
        vector<int> mirco;
        bool isThere = false;
        for(int i=1; i<=10000000; i++){
            mircoNum = 30 * i;
                for(int j= mircoNum; j>0; j=j/10){
                    mirco.push_back(j % 10);
                }
            sort(mirco.begin(), mirco.end());
            
//            cout<<"mirco********\n";
//            for(int i=0; i<mirco.size(); i++){
//                cout<<mirco[i]<<"\n";
//            }
//
//            cout<<"v*******\n";
//            for(int i=0; i<v.size(); i++){
//                cout<<v[i]<<"\n";
//            }
            
            if(mirco == v) { isThere = true; break;}
                mirco.clear();
            }

        if(isThere) cout<<mircoNum<<"\n";
        else cout<<"-1\n";
    
    return 0;
}

