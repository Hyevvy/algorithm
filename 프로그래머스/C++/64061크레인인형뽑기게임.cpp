#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int N = board.size(); //N * N
    int answer =0;
    vector<int> picked;
    for(int j=0; j<moves.size(); j++){
        for(int i=0; i<N; i++){
        if(board[i][moves[j]-1] != 0) {
            if(!picked.empty() && picked[picked.size()-1] == board[i][moves[j]-1]) {
                picked.pop_back();
                answer+=2;
            }
            else picked.push_back(board[i][moves[j]-1]);
            board[i][moves[j]-1]=0;
            break;
            }
        }
    }
    return answer;
 }
