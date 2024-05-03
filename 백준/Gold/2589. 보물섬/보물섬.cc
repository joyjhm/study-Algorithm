#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char maps[50][50];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,-0};
int result = 0;

int bfs(int y, int x) {

    queue<pair<int,int>> q;
    int distance[50][50] = {0, };
    q.push({y, x});
    distance[y][x] = 1;
    int val = 0;
    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if(ty >= n || tx >= m || ty < 0 || tx < 0)
                continue;
            
            if(maps[ty][tx] == 'L' && distance[ty][tx] == 0) {
                q.push({ty, tx});
                distance[ty][tx] = distance[yy][xx] + 1;
                val = max(val, distance[ty][tx] - distance[y][x]);
            }
            
        }
    }

    return val;

}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(maps[i][j] == 'L') {
                result = max(result, bfs(i, j));
            }
        }
    }

    cout << result;
}