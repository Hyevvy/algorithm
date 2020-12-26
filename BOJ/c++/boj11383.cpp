#include <iostream>
#include <vector>
using namespace std;
bool isEyfa(string a, string b){
    for(int i=0;i<a.size();i++){
        for(int j=i*2; j<=2*i+1; j++){
            if(a[i]!=b[j]) return false;
        }
    }
    return true;
}
int main(){
    int N, M;
    cin>>N>>M;
    vector <string> originals(N);
    vector <string> checked(N);
    int state=0;//강제 종료를 막기 위해 추가로 둔 변수
    for(int i=0;i<N;i++){
        cin>>originals[i];
    }
    for(int i=0;i<N;i++){
        cin>>checked[i];
    }
    for(int i=0; i<N; i++){
        if(!isEyfa(originals[i],checked[i])) {state=1; break;}
        originals[i].clear();
        checked[i].clear();
    }
    if(state==0) cout<<"Eyfa";
    else{
        cout<<"Not Eyfa";
    }
    return 0;
}
