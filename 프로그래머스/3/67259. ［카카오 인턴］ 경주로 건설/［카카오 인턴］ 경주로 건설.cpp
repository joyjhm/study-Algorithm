#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct Point {
    int y;
    int x;
    int dir;
};

int n;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int bfs(vector<vector<int>>& board) {
    queue<Point> q;
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(n, vector<int>(4, INT_MAX)));

    q.push({0,0, 0});
    q.push({0,0, 1});
    visited[0][0][0] = 0;
    visited[0][0][1] = 0;
    while(!q.empty()) {
        auto [y, x, dir] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ty = y + dy[i];
            int tx = x + dx[i];
            int cost;
            if(dir == i) {
                cost = 100;
            }
            else {
                cost = 600;
            }

            if(ty >= n || ty < 0 || tx >= n || tx < 0 || board[ty][tx] == 1)
                continue;
            
            if(visited[y][x][dir] + cost < visited[ty][tx][i]) {
                q.push({ty, tx, i});
                visited[ty][tx][i] = visited[y][x][dir] + cost;
            }    
        }
    }

 
    return min({visited[n - 1][n - 1][0], visited[n - 1][n - 1][1], visited[n - 1][n - 1][2], visited[n - 1][n - 1][3]});
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    n = board.size();

    answer = bfs(board);

    return answer;
}