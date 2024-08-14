#include <iostream>
#include <queue>
using namespace std;

struct Status {
    pair<int,int> red;
    pair<int,int> blue;
    int cnt = 0;

};

char board[10][10];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;
pair<int,int> hole;
queue<Status> q;
int result = -1;


void move_ball(pair<int,int> &ball, int& distance, int idx) {

    while(board[ball.first + dy[idx]][ball.second + dx[idx]] != '#' 
    &&board[ball.first][ball.second] != 'O') {
        distance++;
        ball.first += dy[idx];
        ball.second += dx[idx];
    }

}


void bfs() {

    while(!q.empty()) {
        pair<int,int> red = q.front().red;
        pair<int,int> blue = q.front().blue;
        int cnt = q.front().cnt;
        q.pop();

        if(cnt >= 10) {
            return;
        }

        for (int i = 0; i < 4; i++) {   // R, D, L, U
            pair<int,int> tmp_red(red.first, red.second);
            pair<int,int> tmp_blue(blue.first, blue.second);

            int distance_red = 0;
            int distance_blue = 0;
            move_ball(tmp_red, distance_red, i);
            move_ball(tmp_blue, distance_blue, i);

            if(tmp_blue.first == hole.first && tmp_blue.second == hole.second) {
                continue;
            }

            if(tmp_red.first == hole.first && tmp_red.second == hole.second) {
                result = cnt + 1;
                return;
            }

            if(tmp_red.first == tmp_blue.first && tmp_red.second == tmp_blue.second) {
                if(distance_red > distance_blue) {
                    tmp_red.first -= dy[i];
                    tmp_red.second -= dx[i];
                } else {
                    tmp_blue.first -= dy[i];
                    tmp_blue.second -= dx[i];
                }
            }

            if(red.first == tmp_red.first && red.second == tmp_red.second
             && blue.first == tmp_blue.first && blue.second == tmp_blue.second) {
               continue; 
            }

            q.push({tmp_red, tmp_blue, cnt + 1});
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
            if(board[i][j] == 'O') {
                hole.first = i;
                hole.second = j;
            }
        }
    }

    q.push({red, blue, 0});
    bfs();

    cout << result;

}