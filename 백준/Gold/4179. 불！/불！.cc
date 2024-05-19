#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char map[1000][1000];

int visited[1000][1000];
int visited_fire[1000][1000];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int r, c;
int y, x, fire_y, fire_x;
queue<pair<int,int>> fire;
int result = 0;
void bfs_fire() {

    while(!fire.empty()) {
        int yy = fire.front().first;
        int xx = fire.front().second;
        fire.pop();

        for (int i = 0; i < 4; i++) {
            int ty = dy[i] + yy;
            int tx = dx[i] + xx;

            if (ty >= r || tx >= c || ty < 0 || tx < 0)
                continue;

            if (map[ty][tx] != '#' && visited_fire[ty][tx] == 0) {
                visited_fire[ty][tx] = visited_fire[yy][xx] + 1;
                fire.push({ty, tx});
            }
        }

    }

}

int bfs() {

    queue<pair<int,int>> q;
    q.push({y, x});
    while(!q.empty()) {

        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = dy[i] + yy;
            int tx = dx[i] + xx;

            if (ty >= r || tx >= c || ty < 0 || tx < 0) {
                return visited[yy][xx];
            }

            if (map[ty][tx] != '#' && (visited_fire[ty][tx] == 0 || visited[yy][xx] + 1 < visited_fire[ty][tx]) && !visited[ty][tx]) {
                visited[ty][tx] = visited[yy][xx] + 1;
                q.push({ty, tx});
            }

        }
    }

    return -1;
}


int main() {

    cin >> r >> c;
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'J') {
                y = i;
                x = j;
                visited[y][x] = 1;
            }
            else if(map[i][j] == 'F') {
                fire.push({i, j});
                visited_fire[i][j] = 1;
            }
        }
    }

    bfs_fire();
    result = bfs();

    if (result > 0) {
        cout << result;
    } else {
        cout << "IMPOSSIBLE";
    }
}