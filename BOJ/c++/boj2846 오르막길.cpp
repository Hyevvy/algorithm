#include <iostream>
#include <vector>
using namespace std;
int main(){
    int tc;
    cin >> tc;
    
    //입력받기
    vector<int> v(tc);
    for(int i=0; i<tc; i++){
        cin>>v[i];
    }
    
    //ToDoList
    //1. 이전값보다 작으면 오르막길X -> break조건
    //2. break되는 순간 길이 측정 -> 길이 vector에 넣기
    
    int state = 0;
    //state : 1 => 오르막길이 아니다.
    vector<int> lengthV;
    int curr = v[1];
    int prev = v[0];
    int min = v[0];
    for(int i=1; i<v.size(); i++){
        prev = v[i-1];
        curr = v[i];
        if(state == 1){
            min = prev;
            state = 0;
        }
        if(prev >= curr){
            //이전값보다 현재가 작거나 같으면 오르막길이 아님 -> break조건
            //이 때 길이를 측정해야함.
            cout<<"i: "<< i << " prev : "<<prev<<" curr: "<<curr<<" min: " <<min <<"\n";
            int length = prev - min;
            if(length != 0) lengthV.push_back(length);
            state = 1;
        }
    }
    cout<<" 마지막: "<< " prev : "<<prev<<" curr: "<<curr<<" min: " <<min <<"\n";
    //마지막은?
    if(v[v.size()-1] > curr) lengthV.push_back(v[v.size()-1] - curr);
    
    for(int i=0; i<lengthV.size(); i++){
        cout<<lengthV[i]<<"\n";
    }
    
    return 0;
}
