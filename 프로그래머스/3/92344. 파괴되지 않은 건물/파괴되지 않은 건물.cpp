#include <string>
#include <vector>

using namespace std;

int n, m;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n = board.size();
    m = board[0].size();

    vector<vector<int>> diff(n + 1, vector<int>(m + 1));

    for (int k = 0; k < skill.size(); k++) {
        int type = skill[k][0];
        int r1 = skill[k][1];
        int c1 = skill[k][2];
        int r2 = skill[k][3];
        int c2 = skill[k][4];
        int val = skill[k][5];

        if(type == 1) {
            diff[r1][c1] -= val;
            diff[r1][c2 + 1] += val;
            diff[r2 + 1][c1] += val;
            diff[r2 + 1][c2 + 1] -= val;              
        }
        else {
            diff[r1][c1] += val;
            diff[r1][c2 + 1] -= val;
            diff[r2 + 1][c1] -= val;
            diff[r2 + 1][c2 + 1] += val;
        }                
        
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            diff[i][j] += diff[i][j - 1];
        }
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            diff[i][j] += diff[i - 1][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + diff[i][j] > 0) {
                answer++;
            }
        }
    }


    return answer;
}