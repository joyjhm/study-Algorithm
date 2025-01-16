#include <iostream>
#include <cstring>
using namespace std;

int n;
int board[100][100];
long long dp[100][100];

long long dfs(int y, int x) {

    if (y >= n || x >= n) 
        return 0;
    if (y == n - 1 && x == n - 1)
         return 1;

    if (dp[y][x]) {
        return dp[y][x]; 
    }

    int jump = board[y][x];

    if (jump == 0) {
        return 0;
    }

    dp[y][x] = dfs(y + jump, x) + dfs(y, x + jump);

    return dp[y][x];
}

int main() {
    cin >> n;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    cout << dfs(0, 0) << endl;

}
