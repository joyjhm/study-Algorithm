#include<iostream>
#include<vector>
using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r,c;
char board[20][20];
bool visited[26];
int result = 0;
void dfs(int ty, int tx, int depth) {

    if (result < depth) {
        result = depth;
    }

    for(int i = 0; i < 4; i++) {
        int y = ty + dy[i];
        int x = tx + dx[i];
        if(y < 0 || y >= r || x < 0 || x >= c)
            continue;
        int target = board[y][x];

        if(!visited[target - 65]) {
            visited[target - 65] = true;
            dfs(y, x, depth + 1);
            visited[target - 65] = false;
        }

    }

}

int main() {

    cin >> r >> c;

    for(int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    visited[board[0][0] - 65] = true;
    dfs(0,0, 1);

    cout << result;


}