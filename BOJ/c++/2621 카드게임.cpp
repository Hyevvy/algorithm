#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
using p = pair<char, int>;
p arr[6];
vector<int> numbers;
vector<pair<int,int>> v;
int ret;

bool isContinuous(){
    int start = numbers[0];
    for(int i=1; i<5; i++){
        if(numbers[i] != start+1) return false;
        start++;
    }
    return true;
}

void getAboutColor(){
    char firstColor = arr[0].first;
    for(int i=1; i<5; i++){
        if(firstColor != arr[i].first) return ;
    }
    
    
    // 1. 카드 5장이 모두 같은 색이면서 숫자가 연속적일 때, 점수는 가장 높은 숫자에 900을 더한다
    if(isContinuous()){
        ret = max(ret,900 + numbers[4]);
    }
    // 4. 5장의 카드 색깔이 모두 같을 때 점수는 가장 높은 숫자에 600을 더한다.
    else ret = max(ret, 600 + numbers[4]);
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first > b.first;
}


void getSameNumberCount(int *n){    
    for(int i=1; i<=9; i++){
        if(n[i] != 0){
            v.push_back({n[i], i}); // 몇 개가 동일한 카드인지, 카드 숫자 값
        }
    }
    sort(v.begin(), v.end(), cmp);
    
}

void getAboutNumber(){
    
    int n[10] = {0};
    for(int i=0; i<5; i++){
        n[numbers[i]]++;
    }

    getSameNumberCount(n);
    
    // 2. 카드 5장 중 4장의 숫자가 같을 때 점수는 같은 숫자에 800을 더한다. 예를 들어, 카드가 B3, R3, B7, Y3, G3 일 때 점수는 803(=3+800)점이다.
    
    if(v.size() == 2){
        if(v[0].first == 4) ret = max(ret, 800 + v[0].second);
        
        // 3. 카드 5장 중 3장의 숫자가 같고 나머지 2장도 숫자가 같을 때 점수는 3장이 같은 숫자에 10을 곱하고 2장이 같은 숫자를 더한 다음 700을 더한다. 예를 들어, 카드가 R5, Y5, G7, B5, Y7 일 때 점수는 757(=5x10+7+700)점이다.
        
        else if(v[0].first == 3) {
            ret = max(ret, 10 * v[0].second + v[1].second + 700);
        }
    }
    
    // 6. 카드 5장 중 3장의 숫자가 같을 때 점수는 같은 숫자에 400을 더한다. 예를 들어 R7, Y7, R2, G7, R5 일 때 점수는 407(=7+400)점이다.
    
    if(v[0].first == 3) {
        ret = max(ret, 400 + v[0].second);
    }
    
    
    // 7. 카드 5장 중 2장의 숫자가 같고 또 다른 2장의 숫자가 같을 때 점수는 같은 숫자 중 큰 숫자에 10을 곱하고 같은 숫자 중 작은 숫자를 더한 다음 300을 더한다. 예를 들어, R5, Y5, Y4, G9, B4 일 때 점수는 354(=5X10+4+300)점이다.
    
    
    // 8. 카드 5장 중 2장의 숫자가 같을 때 점수는 같은 숫자에 200을 더한다. 예를 들어, R5, Y2, B5, B3, G4 일 때 점수는 205(=5+200)점이다.
    

    if(v[0].first == 2){
        if(v[1].first == 2){
            int maxNum = max(v[0].second, v[1].second);
            int minNum = min(v[0].second, v[1].second);
            ret = max(ret, maxNum * 10 + minNum + 300);
        }
        else {
            ret = max(ret, 200 + v[0].second);
        }
    }
    
}


int main(){
    for(int i=0; i<5; i++){
        cin >> arr[i].first >> arr[i].second;

    }

    for(int i=0; i<5; i++){
        numbers.push_back(arr[i].second);
    }
    sort(numbers.begin(), numbers.end());
    
    
    // 5. 카드 5장의 숫자가 연속적일 때 점수는 가장 높은 숫자에 500을 더한다. 예를 들어 R7, R8, G9, Y6, B5 일 때 점수는 509(=9+500)점이다.
    if(isContinuous()) ret = max(ret, 500 + numbers[4]);
    
    getAboutColor();
    getAboutNumber();
    cout << max(ret, 100 + numbers[4]);
    return 0;
}
