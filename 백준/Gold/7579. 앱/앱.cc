#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int memory[101];
int cost[101];
int n, m;
int result = 10000000;
int dp[101][10001];

int main() {
    cin >> n >> m;
    


    for (int i = 1; i <= n; i++) {
        cin >> memory[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= n; i++) {      // 앱 
        for (int j = 0; j <= 10000; j++) {
            if(j == 0 || dp[i - 1][j]) {
                dp[i][j + cost[i]] = dp[i - 1][j] + memory[i];  // 담았을 때
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);                // 안 담았을 때 
            }
        }
    }

    for (int i = 0; i <= 10000; i++) {
        if(dp[n][i] >= m) {
            result = i;
            break;
        }
    }

    cout << result;
}

