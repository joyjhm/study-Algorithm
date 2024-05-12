#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Water {
    int y;
    int x;
    int cnt;
};


int r, c;
char forest[50][50];
int visited_water[50][50];
int visited[50][50];
queue<pair<int,int>> water;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int start_y, start_x, target_y, target_x;
// S -> 고슴도치, D -> 굴

int bfs() {
    queue<pair<int,int>> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = 1;
    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if (ty >= r || tx >= c || tx < 0 || ty < 0)
                continue;
            
            if(!visited[ty][tx] && (visited_water[ty][tx] > visited[yy][xx] + 1 || visited_water[ty][tx] == 0) && forest[ty][tx] != 'X') {
                visited[ty][tx] = visited[yy][xx] + 1;
                q.push({ty, tx});
            }

            if(forest[ty][tx] == 'D') {
                return visited[yy][xx];
            }
        }
    }

    return 0;
}

void water_bfs() {

    while(!water.empty()) {
        
        int yy = water.front().first;
        int xx = water.front().second;
        water.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if (ty >= r || tx >= c || tx < 0 || ty < 0)
                continue;

            if(!visited_water[ty][tx] && forest[ty][tx] != 'X' && forest[ty][tx] != 'D') {
                visited_water[ty][tx] = visited_water[yy][xx] + 1;
                water.push({ty, tx});
            }
        }

    }

}


int main() {

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> forest[i][j];
            if(forest[i][j] == 'S') {
                start_y = i;
                start_x = j;
            }
            else if(forest[i][j] == 'D') {
                target_y = i;
                target_x = j;
            }
            else if(forest[i][j] == '*') {
                water.push({i, j});
                visited_water[i][j] = 1;
            }
        }
    }

    water_bfs();    
    int result = bfs();

    if(result) {
        cout << result;
    } else {
        cout << "KAKTUS";
    }

    
}