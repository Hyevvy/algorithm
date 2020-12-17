#include <iostream>
using namespace std;
void printStar(int n){
    //2와의 차이 값을 인자로 받고 "*차이값*"을 출력해주는 함수
    cout<<"*";
    for(int i=0;i<n-2;i++) cout<< " ";
    cout<<"*";
}
void printFirstStar(int inputNum){
    for(int i=0;i<inputNum;i++){
        cout<<"*";
    }
    for(int i=0;i<(inputNum-2)*2+1;i++){
        cout<<" ";
    }
    for(int i=0;i<inputNum;i++){
        cout<<"*";
    }
    cout<<"\n";
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int inputNum;
    cin>>inputNum;
    printFirstStar(inputNum);
    for(int j=1;j<inputNum-1;j++){
        for(int k=0;k<j;k++)
        cout<<" ";
        printStar(inputNum);
        for(int k=inputNum;k>j+1;k=k-1) cout<<" ";
        for(int k=inputNum;k>j+2;k=k-1) cout<<" ";
        printStar(inputNum);
        cout<<endl;
    }
    
    for(int k=0;k<inputNum-1;k++) cout<<" ";
    printStar(inputNum);
    for(int k=0;k<inputNum-2;k++) cout<<" ";
    cout<<"*";
    cout<<endl;
    
    // 다리만들기
    for(int i=2;i<inputNum;i++){
        for(int k=inputNum;k>i;k--) cout<<" ";
        printStar(inputNum);
        for(int j=0;j<i-1;j++) cout<<" ";
        for(int j=1;j<i-1;j++) cout<<" ";
        printStar(inputNum);
        cout<<endl;
    }
    printFirstStar(inputNum);
    return 0;
}
