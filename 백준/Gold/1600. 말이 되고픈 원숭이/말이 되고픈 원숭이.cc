#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int y;
    int x;
    int k;
    int cnt;
};

int map[200][200];
bool visited[200][200][31];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int horse_y[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int horse_x[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int result = -1;
int k, w, h;


void bfs() {
    queue<Point> q;
    q.push({0, 0, k, 0});
    visited[0][0][0] = true;
    visited[0][0][1] = true;
    while(!q.empty()) {

        int y = q.front().y;
        int x = q.front().x;
        int kk = q.front().k;
        int cnt = q.front().cnt;
        q.pop();

        if(y == h - 1 && x == w - 1) {
            result = cnt;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy >= h || xx >= w || yy < 0 || xx < 0)
                continue;
            
            if(map[yy][xx] == 0 && !visited[yy][xx][kk]) {
                visited[yy][xx][kk] = true;
                q.push({yy, xx, kk, cnt + 1});
            }
        }

        if (kk > 0) {
            for (int i = 0; i < 8; i++) {

                int yy = y + horse_y[i];
                int xx = x + horse_x[i];

                if (yy >= h || xx >= w || yy < 0 || xx < 0)
                    continue;

                if(map[yy][xx] == 0 && !visited[yy][xx][kk - 1]) {
                    visited[yy][xx][kk - 1] = true;
                    q.push({yy, xx, kk - 1,  cnt + 1});
                }
            }
        }

    }

}

int main() {
    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> map[i][j];
        }
    }

    bfs();

    cout << result;

}