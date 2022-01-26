#include <iostream>
using namespace std;
int N, M;
int A[100010];
int maxRet = -1e9;
int getNum(int num){
    //배정된 예산이 num일 때 지방의 예산 배정 총액
    int sum = 0;
    for(int i=0; i<N; i++){
        if(A[i] < num) sum += A[i];
        else sum+= num;
    }
    return sum;
}

int binSearch(int left, int right){
    while(left <= right){
        int mid = (left + right) / 2;
        int midVal = getNum(mid);
        if(midVal == M) {
            maxRet = mid;
            break;
        }
        //배정 총액 > 전체 국가 예산
        else if(midVal > M) {
            right = mid - 1;
        }
       
        else if(midVal < M) {
            left = mid + 1;
            maxRet = max(maxRet, mid);
        }
    }
    return maxRet;
}



int sorted[1000010];
void merge(int start, int mid, int end){
    int i, j, k;
    i = start; j = mid+1; k = start;
    while(i <= mid && j <= end){
        if(A[i] <= A[j])
            sorted[k++] = A[i++];
        else sorted[k++] = A[j++];
    }
    
    if(i>mid){
        while(j<=end) sorted[k++] = A[j++];
    }
    else {
        while(i <= mid) sorted[k++] = A[i++];
    }
    
    for(int i=start; i<=end; i++){
        A[i] = sorted[i];
    }
}

void merge_sort(int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        merge_sort(start, mid);
        merge_sort(mid+1, end);
        merge(start, mid, end);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> M;
    
    merge_sort(0, N-1);
    
   
    int ans = binSearch(min(A[0], M/N), A[N-1]);
    cout << ans <<"\n";
    return 0;
}
