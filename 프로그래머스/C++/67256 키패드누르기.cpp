#include <string>
#include <cstring>
#include <queue>
#include <iostream>
#include <vector>
int arr[][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,0,12} };
int roffset[] = { 0, 0, -3, +3 };
int coffset[] = { -1, 1, 0, 0 };
bool visited[20][3];
using namespace std;
using p = pair<int, int>;
p getCoordinates(int n) {
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j < 3; j++)
            if (arr[i][j] == n) return { i,j };
    }
}
int lds[] = { 1, 4, 7 };
int rds[] = { 1, 2, 5 };
string shortDist(int l, int r, int target) {
    p lc = getCoordinates(l);
    p rc = getCoordinates(r);
    p tc = getCoordinates(target);


    int ld = abs(lc.first - tc.first) + abs(lc.second - tc.second);
    int rd = abs(rc.first - tc.first) + abs(rc.second - tc.second);

    if (ld == rd) return "same";
    if (rd < ld) return "R";
    else return "L";

}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int currL = 10, currR = 12;
    for (auto curr : numbers) {
        if (curr == 1 || curr == 4 || curr == 7) {
            currL = curr;
            answer += "L";
        }
        else if (curr == 3 || curr == 6 || curr == 9) {
            currR = curr;
            answer += "R";
        }
        else {
            //거리를 비교해서 같으면 hand에 따라 , 같지 않으면 거리가 짧은 손가락으로
            string ans = shortDist(currL, currR, curr);

            if (ans == "same") {
                if (hand == "right") {
                    currR = curr;
                    answer += "R";
                }
                else {
                    currL = curr;
                    answer += "L";
                }
            }
            else {

                if (ans == "L") {
                    currL = curr;
                    answer += "L";
                }
                else {
                    currR = curr;
                    answer += "R";
                }

            }
        }

    }

    return answer;
}