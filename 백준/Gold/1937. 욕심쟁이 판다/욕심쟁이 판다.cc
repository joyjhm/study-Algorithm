#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
    int y;
    int x;
    int cnt;
};

int n;
int forest[500][500];
int dp[500][500];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int dfs(int y, int x) {

    if(dp[y][x] != 0) {
        return dp[y][x];
    }

    dp[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int yy = y + dy[i];
        int xx = x + dx[i];

        if (yy >= n || yy < 0 || xx >= n || xx < 0)
            continue;

        if(forest[y][x] < forest[yy][xx]) {
            dp[y][x] = max(dfs(yy, xx) + 1, dp[y][x]);
        }
    }
    return dp[y][x];
}


int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> forest[i][j];
        }
    }


    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = max(result, dfs(i, j));
        }
    }

    cout << result;
}