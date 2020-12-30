//재귀버전
#include <iostream>
#include <vector>
using namespace std;
int N,M;
int maxCardSum=0;
int maxCardNum=3;
vector<int> myCard;
void checkSum(int index, int start, int sum){
    if(index==3) {
        if(sum>maxCardSum && sum<=M){ maxCardSum = sum;}
        return;
    }
    for(int i=start; i<N; i++){
      //  cout<<"현재:"<<index<< start<<sum<<endl;
        checkSum(index+1, i+1, sum + myCard[i]);
    }
}
int main(){
    int temp;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>temp;
        myCard.push_back(temp);
    }
    checkSum(0,0,0);
    cout<<maxCardSum<<"\n";
    return 0;
}

//삼중포문버전
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N, M;
    cin>>N>>M;
    vector<int> myCard(N);
    for(int i=0;i<N;i++){
        cin>>myCard[i];
    }
    int max=0;
    int temp;
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            for(int k=0; k<N; k++){
                temp = myCard[i]+myCard[j]+myCard[k];
                if(i==k || j==k || i==j) continue;
                if(temp==M) {cout<<temp; return 0;}
                if(temp>max && temp<M) max=temp;
            }
        }
    }
    cout<<max;
    return 0;
}

