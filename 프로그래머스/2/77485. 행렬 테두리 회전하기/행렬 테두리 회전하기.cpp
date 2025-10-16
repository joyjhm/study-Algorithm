#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX_INT 100000

using namespace std;

int rotate(vector<vector<int>>& board, vector<int> query) {
    int y1 = query[0];
    int x1 = query[1];
    int y2 = query[2];
    int x2 = query[3];
    int result = MAX_INT;
    int tmp_1 = board[y1 + 1][x1];
    int tmp_2;

    for (int i = x1; i <= x2; i++) {
        tmp_2 = board[y1][i];
        board[y1][i] = tmp_1;
        result = min(result, tmp_1);
        tmp_1 = tmp_2; 
        
        
    }

    for (int i = y1 + 1; i <= y2; i++) {
        tmp_1 = board[i][x2];
        board[i][x2] = tmp_2;
        result = min(result, tmp_2);
        tmp_2 = tmp_1;
    }

    for (int i = x2 - 1; i >= x1; i--) {
        tmp_1 = board[y2][i];
        board[y2][i] = tmp_2;
        result = min(result, tmp_2);
        tmp_2 = tmp_1;
    }

    for (int i = y2 - 1; i >= y1; i--) {
        tmp_1 = board[i][x1];
        board[i][x1] = tmp_2;
        result = min(result, tmp_2);
        tmp_2 = tmp_1;
    }
    
    return result;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> board(rows + 2, vector<int>(columns + 2));

    int idx = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            board[i][j] = idx++;
        }
    }
    int n = queries.size();
    for (int i = 0; i < n; i++) {
        int num = rotate(board, queries[i]);
        answer.push_back(num);
    }
    
    return answer;
}