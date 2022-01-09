#include <iostream>
#include <vector>
using namespace std;
vector<char> tree[30];
int N;
void prefix(char curr){
    cout << curr;
    if(tree[curr-'A'][0]!='.') prefix(tree[curr-'A'][0]);
    if(tree[curr-'A'][1]!='.') prefix(tree[curr-'A'][1]);
}
void infix(char curr){
    if(tree[curr-'A'][0]!='.') infix(tree[curr-'A'][0]);
    cout<<curr;
    if(tree[curr-'A'][1]!='.') infix(tree[curr-'A'][1]);
}
void postfix(char curr){

    if(tree[curr-'A'][0]!='.') postfix(tree[curr-'A'][0]);
    if(tree[curr-'A'][1]!='.') postfix(tree[curr-'A'][1]);
    cout<<curr;
}
int main(){
    cin >> N;
    char root, left, right;
    for(int i=0; i<N; i++){
        cin >> root >> left >> right;
        tree[root-'A'].push_back(left);
        tree[root-'A'].push_back(right);
    }
    prefix('A');
    cout<<"\n";
    infix('A');
    cout<<"\n";
    postfix('A');
    return 0;
}
