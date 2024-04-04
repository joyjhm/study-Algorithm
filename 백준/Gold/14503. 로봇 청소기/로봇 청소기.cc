#include <iostream>

using namespace std;

int n, m, r, c, d;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int room[50][50];

int clean() {
    int y = r;
    int x = c;
    int cnt = 0;

    while(true) {
        
        if(room[y][x] == 0) {
            room[y][x] = 2;
            cnt++;
        }
        else {
            bool isClean = true;
            for (int i = 0; i < 4; i++) {
                int ty = y + dy[i];
                int tx = x + dx[i];

                if (room[ty][tx] == 0) {
                    isClean = false;
                    break;
                }
            }

            if(isClean) {
                y -= dy[d];
                x -= dx[d];

                if (y < 0 || x < 0 || y >= n || x >= m)
                    break;
                if (room[y][x] == 1)
                    break;

            } else {
                d--;
                if(d == -1) {
                    d = 3;
                }

                int ty = y + dy[d];
                int tx = x + dx[d];

                if(ty >= n || tx >= m || ty < 0|| tx < 0)
                    continue;

                if(room[ty][tx] == 0) {
                    y = ty;
                    x = tx;
                }
            }
        }
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }

    int answer = clean();
    cout << answer;
}