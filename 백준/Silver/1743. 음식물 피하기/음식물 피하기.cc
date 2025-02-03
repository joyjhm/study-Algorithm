#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
bool road[101][101];
bool visited[101][101];
int answer = 0;
int n, m, k;


int bfs(int y, int x) {

    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = true;
    int cnt = 0;

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if(ty <= 0 || ty > n || tx <= 0 || tx > m) {
                continue;
            }

            if(road[ty][tx] && !visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({ty, tx});
            }
        }

    }

    return cnt;
}

int main() {

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        road[y][x] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(road[i][j] && !visited[i][j]) {
                int cnt = bfs(i, j);
                answer = max(cnt, answer);
            }
        }
    }

    cout << answer;
}