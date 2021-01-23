#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    cout.setf(ios::fixed);
    cout.precision(2);
    int num;
    cin>>num;
    string postfix;
    cin>>postfix;
    vector<int> inputNum(num);
    for(int i=0; i<num; i++)
        cin>>inputNum[i];
    for(int i=0; i<postfix.size(); i++){
        if(postfix[i]>='A'&&postfix[i]<='Z') {postfix[i]=inputNum[postfix[i]-'A']+'0';}
    }
    double op1, op2;
    stack<double> v;
    for(int i=0;i<postfix.size();i++){
        if(postfix[i]=='*'||postfix[i]=='-'||postfix[i]=='+'||postfix[i]=='/'){
            op1=v.top();
            v.pop();
            op2=v.top();
            v.pop();
            if(postfix[i]=='*') v.push(op1*op2 );
            else if(postfix[i]=='/') {v.push(op2/op1);}
            else if(postfix[i]=='+') v.push(op1+op2);
            else if(postfix[i]=='-') v.push(op2-op1);
        }
        else v.push(postfix[i]-'0');
    }
    cout<<v.top();
    return 0;
}

