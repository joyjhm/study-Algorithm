#include <iostream>

using namespace std;

int dp[30][30];

int main() {

    int t, m, n;
    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;

    for (int i = 2; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    while (t--) {
        cin >> n >> m;
        cout << dp[m][n] << endl;
        
    }
}