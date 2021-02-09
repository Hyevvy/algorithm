#include <string>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> p, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    for(int i=0; i<p.size(); i++) q.push(make_pair(p[i], i));
    sort(p.begin(),p.end(),[](int u, int v){return u>v;});
   int idx=0;
   while(!q.empty()){
           if(q.front().first == p[idx]){
               answer++;
               if(q.front().second == location){
                   return (answer);
               }
               q.pop();
               idx++;
               
            }
           else {
               pair<int, int> curr = q.front();
               q.pop();
               q.push(curr);
           }
       
   }
    return answer;
}
