#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main(){
    int tc;
    cin>>tc;
    string command;
    int temp;
    for(int i=0; i<tc; i++){
        cin>>command;
        if(command=="push_back"){
            cin>>temp;
            dq.push_back(temp);
        }
        else if(command=="push_front"){
            cin>>temp;
            dq.push_front(temp);
        }
        else if(command=="pop_back"){
            if(dq.empty()) cout<<"-1\n";
            else{
                int back = dq.back();
                dq.pop_back();
                cout<<back<<"\n";
            }
        }
        else if(command=="pop_front"){
            if(dq.empty()) cout<<"-1\n";
            else{
                int front = dq.front();
                dq.pop_front();
                cout<<front<<"\n";
            }
        }
        else if(command=="front"){
            if(dq.empty()) cout<<"-1\n";
            else cout<<dq.front()<<"\n";
        }
        else if(command=="back"){
            if(dq.empty()) cout<<"-1\n";
            else cout<<dq.back()<<"\n";
        }
        else if(command=="size"){
            cout<<dq.size()<<"\n";
        }
        else if(command=="empty"){
            if(dq.empty()) cout<<"1\n";
            else cout<<"0\n";
        }
    }
    return 0;
}

