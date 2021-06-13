#include <iostream>
#include <deque>
using namespace std;
int main(){
    int N , M; //큐의 크기, 뽑아내고자 하는 개수
    cin >> N >> M;
    deque<int> dq;
    int want[51] = {0,};
    
    for(int i=0; i<N; i++){
        dq.push_back(i+1);
    }
    
    for(int i=0; i<M; i++){
        cin >> want[i];
    }
    
    int idx = 0;
    int result = 0; // 최소값 계산을 위함
  
    for(int i = 0; i < M ; i++){
        //1. idx 확인
        for(int j = 0; j < dq.size(); j++){
            if(want[i] == dq[j]) idx = j;
        }
        
        //2. 왼쪽이면 2번 연산 수행
        if(idx <= dq.size() / 2){
            //pop_front -> push_back
            
            for(int i=0; i<idx; i++){
                int temp = dq.front();
                dq.push_back(temp);
                dq.pop_front();
                result++;
//                cout<<"left\n";
            }
           
         //   cout<<"왼쪽에서. 현재값 : "<<dq[idx]<<"\n";
        }
        
        //3. 오른쪽이면 3번 연산 수행
        
        if( idx > dq.size() / 2){
            
            for(int i=0; i< dq.size() - idx; i++){
                int temp = dq.back();
                dq.push_front(temp);
                dq.pop_back();
                result++;
//                cout<<"right\n";
               // cout<<"오른쪽에서 현재값 : "<<dq[idx]<<"\n";
            }
        }
        
        dq.pop_front();
    }
    
    //최솟값 출력
    
    cout << result <<"\n";
    return 0;
}

