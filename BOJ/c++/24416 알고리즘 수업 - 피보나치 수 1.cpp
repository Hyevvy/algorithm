#include <iostream>
using namespace std;
int N;
int a, b;
int f[41];
int fib(int n){
    if(n==1 || n==2) {
        a++;
        return 1;
    }
    else return fib(n-1) + fib(n-2);
}
int fibonacci(int n){
    f[1] = 1; f[2] = 1;
    for(int i=3; i<=n; i++){
        f[i] = f[i-1] + f[i-2];
        b++;
    }
    return f[n];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    fib(N);
    fibonacci(N);
    cout << a<<" " << b<<"\n";
    return 0;
}
