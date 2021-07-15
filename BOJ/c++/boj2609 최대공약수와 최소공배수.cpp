#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int gcd(int a, int b){
    if(a % b == 0) return b;
    return gcd(b, a%b);
}
int main(){
    int a, b;
    cin >> a >> b;
    
    int gcdNum = 0;
    a > b ? gcdNum = gcd(a, b) : gcdNum = gcd(b, a);
    
    cout << gcdNum<<"\n" << a * b / gcdNum << "\n";
    
    
    return 0;
}


