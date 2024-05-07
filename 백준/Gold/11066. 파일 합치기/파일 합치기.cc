#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int main() {

    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;
        vector<int> sum(k + 1, 0);
        int dp[501][501] = {0, };

        for (int i = 1; i <= k; i++) {
            int tmp;
            cin >> tmp;
            sum[i] = sum[i - 1] + tmp;
        }

        for (int i = 1; i < k; i++) {
            for (int x = 1; x <= k - i; x++) {
                int y = x + i;
                dp[x][y] = INT_MAX;

                for (int m = x; m < y; m++) {
                    dp[x][y] = min(dp[x][y], dp[x][m] + dp[m + 1][y] + sum[y] - sum[x - 1]);

                }
            }

        }

        cout << dp[1][k] << '\n';
        
    }

}

