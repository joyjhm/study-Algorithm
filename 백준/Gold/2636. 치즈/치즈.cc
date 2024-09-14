#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int row, col;
int board[100][100];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
bool visited[100][100];

queue<pair<int,int>> q;
vector<pair<int,int>> target;
int result = 0;
int cnt = 0;

void bfs() {

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if(ty >= row - 1 || ty < 0 || tx >= col || tx < 0)
                continue;

            if(visited[ty][tx])
                continue;
            
            if(board[ty][tx]) {
                target.push_back({ty, tx});
                visited[ty][tx] = true;
            } else {
                q.push({ty, tx});
                visited[ty][tx] = true;
            }
        }
    }
}

int main() {

    cin >> row >> col;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(i == 0 || i == row - 1 || j == 0 || j == col - 1) {
                q.push({i, j});
            }
        }
    }
    while(true) {
        bfs();
        if(target.empty()) {
            break;
        }

        cnt = target.size();
        result++;

        while(!target.empty()) {
            q.push({target.back().first, target.back().second});
            target.pop_back();
        }
    }

    cout << result << '\n' << cnt;

}