#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
char maze[101][101];
int n, m;
int dist[101][101];
queue<pair<int,int>> q;

void bfs() {

    while(!q.empty()) {

        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if(yy > n || yy <= 0 || xx > m || xx <= 0)
                continue;
            
            if(maze[yy][xx] == '1') {
                if(dist[yy][xx] > dist[y][x] + 1) {
                    dist[yy][xx] = dist[y][x] + 1;
                    q.push({yy, xx});
                }

            }
            else {
                if(dist[yy][xx] > dist[y][x]) {
                    dist[yy][xx] = dist[y][x];
                    q.push({yy, xx});
                }
            }
        }

    }


}

int main() {

    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maze[i][j];
        }
    } 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = 1000000;
        }
    }

    dist[1][1] = 0;
    q.push({1,1});
    bfs();

    cout << dist[n][m];
}