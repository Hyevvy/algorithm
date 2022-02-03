#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;
using p = pair<int, int>;
int N, M, K;
int arr[60][60]; //원본 배열
int copied[60][60]; //복사 배열

struct Rotate{
    int r, c, s;
    Rotate(int tr, int tc, int ts){
        r = tr;
        c = tc;
        s = ts;
    }
};
vector<Rotate> rotates;

void rotate(int r, int c, int s){
    
    while(s>0){
        deque<int> q;
        
        for(int j=c-s; j<=c+s; j++){
            q.push_back(copied[r-s][j]);
        }
        for(int i=r-s+1; i<=r+s; i++){
            q.push_back(copied[i][c+s]);
        }
        for(int j=c+s-1; j>=c-s; j--){
            q.push_back(copied[r+s][j]);
            
        }
        for(int i=r+s-1; i>=r-s+1; i--){
            q.push_back(copied[i][c-s]);
        }
        
        int tmp = q.back();
        q.pop_back();
        q.push_front(tmp);
        
        for(int j=c-s; j<=c+s; j++){
            copied[r-s][j] = q.front();
            q.pop_front();
        }
        for(int i=r-s+1; i<=r+s; i++){
            copied[i][c+s] = q.front();
            q.pop_front();
        }
        for(int j=c+s-1; j>=c-s; j--){
            copied[r+s][j] = q.front();
            q.pop_front();
        }
        for(int i=r+s-1; i>=r-s; i--){
            copied[i][c-s] = q.front();
            q.pop_front();
        }

        s--;
    }
}

int getMin(int arr[60][60]){
    int minVal = 1e9;
    for(int i=1; i<=N; i++){
        int tmp = 0;
        for(int j=1; j<=M; j++){
            tmp += arr[i][j];
        }
        minVal = min(tmp, minVal);
    }
    return minVal;
}

void copyArr(int arr[60][60], int copied[60][60]){
    for(int i=1; i <= N; i++){
        for(int j=1; j<=M; j++){
            copied[i][j] = arr[i][j];
        }
    }
}

bool visited[7];
vector<int> nums;
int ret = 1e9;
void getPermutation(int cnt){
    if(cnt == K){
        copyArr(arr, copied);
        for(int curr : nums){
            rotate(rotates[curr].r, rotates[curr].c, rotates[curr].s);
        }
        ret = min(getMin(copied), ret);
    }
    for(int i=0; i<K; i++){
        if(!visited[i]){
            nums.push_back(i);
            visited[i] = true;
            getPermutation(cnt+1);
            nums.pop_back();
            visited[i] = false;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> K;
    for(int i=1; i <= N; i++){
        for(int j=1; j<=M; j++){
            cin >> arr[i][j];
        }
    }
    
    

    int tr, tc, ts;
    for(int i=0; i<K; i++){
        cin >> tr >> tc>> ts;
        rotates.push_back(Rotate(tr, tc, ts));
    }
    getPermutation(0);
    cout<<ret<<"\n";
    return 0;
}
