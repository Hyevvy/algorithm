#include <iostream>
using namespace std;
int arr[3] = { 0,1,2 };
int main() {
    int n, milk;
    cin >> n;
    int idx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> milk;
        if (milk == arr[idx]) {
            idx++;
            cnt++;
        }
        if (idx == 3) {
            idx = 0;
        }
    }
    cout << cnt << "\n";
    return 0;
}