#include <iostream>
#include <queue>
using namespace std;

struct Status {
    pair<int,int> red;
    pair<int,int> blue;
    int cnt = 0;

};

char board[10][10];
int n, m;
queue<Status> q;
int result = -1;


int move_ball(bool isCol, pair<int,int>& ball, pair<int,int>& other, int op, char color) {
    int tmp = isCol ? ball.second : ball.first;
    if(isCol) {
        while(board[ball.first][tmp + op] != '#' && !(tmp + op == other.second && ball.first == other.first) || board[ball.first][tmp + op] == 'O') {
            ball.second = tmp + op;
            if(board[ball.first][tmp + op] == 'O') {
                if(color == 'B') {
                    return -1;
                }
                else {
                    return 1;
                }
            }
            tmp += op;
        }
    } else {
        while(board[tmp + op][ball.second] != '#' && !(tmp + op == other.first && ball.second == other.second) || board[tmp + op][ball.second] == 'O') {
            ball.first = tmp + op;
            if(board[tmp + op][ball.second] == 'O') {
                if(color == 'B') {
                    return -1;
                }
                else {
                    return 1;
                }
            }
            tmp += op;
        }
    
    }    

    return 0;
}

 
int move_board(int idx, pair<int,int>& red, pair<int,int>& blue) {

    int tmp_red;
    int tmp_blue;

    if(idx == 0) {
        if(blue.second > red.second) {
            tmp_blue = move_ball(true, blue, red, 1, 'B');
            tmp_red = move_ball(true, red, blue, 1, 'R');
        }
        else {
            tmp_red = move_ball(true, red, blue, 1, 'R');
            tmp_blue = move_ball(true, blue, red, 1, 'B');
        }
        
    }
    else if(idx == 1) {
        if(blue.first < red.first) {
            tmp_red = move_ball(false, red, blue, 1, 'R');
            tmp_blue = move_ball(false, blue, red, 1, 'B');
        }
        else {
            tmp_blue = move_ball(false, blue, red, 1, 'B');
            tmp_red = move_ball(false, red, blue, 1, 'R');
        }
    }
    else if(idx == 2) {
        if(blue.second < red.second) {
            tmp_blue = move_ball(true, blue, red, -1, 'B');
            tmp_red = move_ball(true, red, blue, -1, 'R');
        }
        else {
            tmp_red = move_ball(true, red, blue, -1, 'R');
            tmp_blue = move_ball(true, blue, red, -1, 'B');
        }
    }
    else if(idx == 3) {
        if(blue.first > red.first) {
            tmp_red = move_ball(false, red, blue, -1, 'R');
            tmp_blue = move_ball(false, blue, red, -1, 'B');
        }
        else {
            tmp_blue = move_ball(false, blue, red, -1, 'B');
            tmp_red = move_ball(false, red, blue, -1, 'R');
        }
    }

    if(tmp_blue == -1) {
        return tmp_blue;
    }

    if(tmp_red == 1) {
        return tmp_red;
    }

   return 0;
}

void bfs() {

    while(!q.empty()) {
        pair<int,int> red = q.front().red;
        pair<int,int> blue = q.front().blue;
        int cnt = q.front().cnt;
        q.pop();

        if(cnt + 1 > 10) {
            return;
        }

        for (int i = 0; i < 4; i++) {   // R, D, L, U
            pair<int,int> tmp_red(red.first, red.second);
            pair<int,int> tmp_blue(blue.first, blue.second);

            int type = move_board(i, tmp_red, tmp_blue);

            if(red.first == tmp_red.first && red.second == tmp_red.second && blue.first == tmp_blue.first && blue.second == tmp_blue.second) {
               continue; 
            }

            if(type == 0) {
                q.push({tmp_red, tmp_blue, cnt + 1});
            }
            else if(type == 1) {
                result = cnt + 1;
                return;
            }
        }
    }
}


int main() {
    
    pair<int,int> red;
    pair<int,int> blue;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                red.first = i;
                red.second = j;
                board[i][j] = '.';
            }
            if(board[i][j] == 'B') {
                blue.first = i;
                blue.second = j;
                board[i][j] = '.';
            }
        }
    }

    q.push({red, blue, 0});
    bfs();

    cout << result;

}