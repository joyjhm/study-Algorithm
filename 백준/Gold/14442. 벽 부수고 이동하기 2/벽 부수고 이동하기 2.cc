#include <iostream>
#include <queue>
#define INF 100000000
using namespace std;

struct Point {
    int y;
    int x;
    int cnt;
    int distance;
};

int n, m, k;
char maps[1001][1001];
queue<Point> q;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int visited[1001][1001];

int bfs() {

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int cnt = q.front().cnt;
        int distance = q.front().distance;
        q.pop();

        if(y == n && x == m) {
            return distance;
        }

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if(yy > n || yy <= 0 || xx > m || xx <= 0)
                continue;
            
            if(maps[yy][xx] == '1') {
                if(visited[yy][xx] != INF && visited[yy][xx] <= cnt + 1) {
                    continue;
                }
                if(cnt + 1 > k) {
                    continue;
                }

                visited[yy][xx] = cnt + 1;
                q.push({yy, xx, cnt + 1, distance + 1});
            }
            else {
                if(visited[yy][xx] != INF && visited[yy][xx] <= cnt) {
                    continue;
                }
                visited[yy][xx] = cnt;
                q.push({yy, xx, cnt, distance + 1});
            }
        }
    }

    return -1;
}

int main() {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = INF;
        }
    }

    q.push({1,1, 0, 1});
    int result = bfs();
    cout << result;
}