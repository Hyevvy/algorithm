#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
bool visited[210];
void dfs(int n, int r, vector<vector<int>>& computers) {
    for (int i = 0; i < n; i++) {
        if (!visited[i] && computers[r][i] == 1) {
            visited[i] = true;
            dfs(n, i, computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(n, i, computers);
            answer++;
        }
    }
    return answer;
}