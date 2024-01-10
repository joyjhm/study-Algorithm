#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;



struct Point {

    int y;
    int x;
    bool isBreak;
    int distance;

    Point(int y, int x, bool isBreak, int distance) {
        this->y = y;
        this->x = x;
        this->isBreak = isBreak;
        this->distance = distance;
    }
};

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int maps[1000][1000];

int n,m;
bool wall[1000][1000];
bool visited[1000][1000];
queue<Point> q;

void bfs() {

    while(!q.empty()) {
        int ty = q.front().y;
        int tx = q.front().x;
        bool isBreak = q.front().isBreak;
        int distance = q.front().distance;
        q.pop();

        if(ty == n - 1 && tx == m - 1) {
            maps[ty][tx] = distance;
            break;
        }

        
        for (int i = 0; i < 4; i++) {
            int x = dx[i] + tx;
            int y = dy[i] + ty;

            if(x >= m || x < 0 || y >= n || y < 0)
                continue;

            if(isBreak) {
                if(wall[y][x]) {
                    maps[y][x] = distance + 1;
                    q.push(Point(y, x, false, distance + 1));
                }
                else if (!maps[y][x]) {
                    maps[y][x] = distance + 1;
                    q.push(Point(y, x, true, distance + 1));
                }
            }
            else {
                if(!wall[y][x] && !maps[y][x] && !visited[y][x]) {
                    visited[y][x] = true;
                    q.push(Point(y, x, false, distance + 1));
                }
            }

        }
    }

}

int main() {

    cin >> n >> m;
    char c;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> c;
            maps[i][j] = c - '0';
            if(maps[i][j] == 1) {
                wall[i][j] = true;
                maps[i][j] = -1;
            }
        }
    }
    maps[0][0] = 1;
    q.push({0,0,true, 1});

    bfs();

    if(!maps[n - 1][m - 1]) {
        cout << -1;
    }
    else {
        cout << maps[n - 1][m - 1];
    }
}