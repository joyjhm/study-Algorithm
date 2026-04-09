#include <string>
#include <vector>

using namespace std;

int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int solution(vector<string> board) {
    int answer = -1;
    int n = 3;

    bool o_win = false;
    bool x_win = false;

    for (int yy = 0; yy < n; yy++) {
        for (int xx = 0; xx < n; xx++) {
            for (int j = 0; j < 8; j++) {
                int o_cnt = 0;
                int x_cnt = 0;
                int y = yy;
                int x = xx;
                while(y < n && y >= 0 && x < n && x >= 0) {
                    if(board[y][x] == 'O') {
                        o_cnt++;
                    }
                    else if(board[y][x] == 'X') {
                        x_cnt++;
                    }
                    y += dy[j];
                    x += dx[j];
                }

                if(o_cnt == 3) {
                    o_win = true;
                } 

                if(x_cnt == 3) {
                    x_win = true;
                }
            }               
        }         
    }
    
    int o_cnt = 0;
    int x_cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(board[i][j] == 'O') {
                o_cnt++;
            }
            else if(board[i][j] == 'X') {
                x_cnt++;
            }
        }
    }
    

    if(o_win && x_win) {
        return false;
    }
    else if(o_win && !x_win && o_cnt - 1 != x_cnt) {
        return false;
    }
    else if(!o_win && x_win && o_cnt != x_cnt) {
        return false;
    }
    else if(!o_win && !x_win && !(o_cnt - 1 == x_cnt || o_cnt == x_cnt)) {
        return false;
    }
    
    return true;
}