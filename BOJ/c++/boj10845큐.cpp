#include <iostream>
#include <string>
#include <queue>
using namespace std;
void pushQ(queue<int>& q){
    int item;
    cin>>item;
    q.push(item);
}
void frontQ(queue<int>& q){
    if(q.empty()) cout<<"-1\n";
    else cout<<q.front()<<"\n";
}
void backQ(queue<int>& q){
    if(q.empty()) cout<<"-1\n";
    else cout<<q.back()<<"\n";
}
void emptyQ(queue<int>& q){
    if(q.empty()) cout<<"1\n";
    else cout<<"0\n";
}
void popQ(queue<int>& q){
    if(q.empty()) cout<<"-1\n";
    else{
        int temp = q.front();
        cout<<temp<<"\n";
        q.pop();
    }
}
void sizeQ(queue<int>& q){
    cout<<q.size()<<"\n";
}
int main(){
    int tc;
    cin>>tc;
    queue<int>q;
    for(int i=0; i<tc; i++){
        string command;
        cin>>command;
        if(command=="push") pushQ(q);
        else if(command=="front") frontQ(q);
        else if(command=="back") backQ(q);
        else if(command=="pop") popQ(q);
        else if(command=="size") sizeQ(q);
        else if(command=="empty") emptyQ(q);
    }
}

