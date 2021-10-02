#include <iostream>
//MergeSort 연습 
using namespace std;
void merge(int *A, int low, int mid, int high){
    int i = low, j = mid + 1, h = low, k = low;
    int B[1000001]; //h는 B의 인덱스
    
    while( i <= mid && j <= high) {
        if(A[i] < A[j]) {
            B[h] = A[i];
            i++;
        }
        else {
            B[h] = A[j];
            j++;
            
        }
        h++;
    }
    
    //i > j or j > high
    while(j <= high){
        B[h] = A[j];
        j++;
        h++;
    }
    
    while(i <= mid){
        B[h] = A[i];
        i++;
        h++;
    }
    
    for(int idx=k; idx<=high; idx++){
        A[idx] = B[idx];
    }
}
void mergeSort(int *A, int low, int high){
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[1000001]={};
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    mergeSort(arr, 0, N-1);
    cout<<arr[0] << " "<<arr[N-1];
    return 0;
}
