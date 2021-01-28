#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main(){
    int totalTime; //이번 학기가 총 몇 분인지
    int totalScore = 0; //총 얻는 과제 점수
    cin>>totalTime;
    int temp; //과제 유무
    int A, T; //과제 만점, 해결하는데 걸리는 시간
    stack<pair<int, int>> assignments; //과제 스택
    // 가장 최근에 하던 걸 이어서 할 것이므로 스택(후입선출)
    // first : 과제 점수 , second : 시간 (시간이 0이 되면 과제점수를 얻음)
    for(int i=0; i<totalTime; i++){
        cin >> temp;
        if(temp==1) {
            cin>> A>> T;
            if(T==1) totalScore += A;
            else {
                assignments.push(make_pair(A, T-1));
            }
        }
        else if(temp!=1 && !assignments.empty()) {
            //이전에 하던 과제 마저하기
            assignments.top().second = assignments.top().second-1;
            if(assignments.top().second == 0) { totalScore+=assignments.top().first; assignments.pop();}
        }
    }
    cout<<totalScore;
    return 0;
}

