#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10001
using namespace std;



int main() {
    int n, k;
    cin >> n >> k;
    vector<int> coin(n);
    vector<int> dp(k + 1, INF);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    dp[0] = 0;
    sort(coin.begin(), coin.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int num = coin[i];
            if(j == 0) {
                dp[j + num] = 1;
                continue;
            }
            if(dp[j] != INF && j + num <= k) {
                dp[j + num] = min(dp[j] + 1, dp[j + num]);
            }
        }
    }

    if(dp[k] != INF) {
        cout << dp[k];
    } else {
        cout << -1;
    }

}