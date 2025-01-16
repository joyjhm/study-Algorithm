#include <iostream>
using namespace std;

int n;
int board[100][100];
long long dp[100][100];


int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == 0 || board[i][j] == 0) 
                continue;

            int jump = board[i][j];
            if (i + jump < n) {
                dp[i + jump][j] += dp[i][j];
            }
            if (j + jump < n) {
                dp[i][j + jump] += dp[i][j];
            }
        }
    }
    cout << dp[n - 1][n - 1];


}