#include <iostream>
#include <queue>

using namespace std;


int maps[501][501];
int m, n;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int dp[501][501];

int cnt = 0;

int dfs(int y, int x) {

    if(y == m && x == n) {
        return 1;
    }
    if(dp[y][x] != -1) {
        return dp[y][x];
    }

    dp[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if (next_y > m || next_x > n || y <= 0 || x <= 0)
            continue;
   
        if (maps[y][x] > maps[next_y][next_x]) {
            dp[y][x] = dp[y][x] + dfs(next_y, next_x);
        }
    }

    return dp[y][x];
}


int main() {

    cin >> m >> n;


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> maps[i][j];
            dp[i][j] = -1;
        }
    }

    int result = dfs(1,1);

    cout << result;
}