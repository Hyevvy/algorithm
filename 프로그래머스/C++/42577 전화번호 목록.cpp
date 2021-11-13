#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
bool solution(vector<string> phone_book) {
    for (auto curr : phone_book) {
        mp[curr]++;
    }

    for (auto curr : phone_book) {
        string temp = "";

        for (int i = 0; i < curr.size(); i++) {
            temp += curr[i];
            if (mp[temp] != 0 && (temp != curr)) return false;
        }
    }

    return true;
}
