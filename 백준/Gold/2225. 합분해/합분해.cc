#include <iostream>
#include <vector>
using namespace std;

long long dp[201][201];

int main() {

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if(j == 1) {
                dp[i][j] = 1;
            }
            else if(i == 0) {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            for (int x = 0; x <= i; x++) {
                dp[i][j] += dp[x][j - 1];
            }
            dp[i][j] = dp[i][j] % 1000000000;
        }
    }

    cout << dp[n][k];
}