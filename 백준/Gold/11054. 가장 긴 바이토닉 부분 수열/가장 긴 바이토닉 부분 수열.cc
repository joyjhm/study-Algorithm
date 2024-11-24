#include<iostream>
using namespace std;

int a[1002];
int dp[2][1002];   // dp[0]은 오름차순 최대, dp[1]은 끝에서부터 오름차순 최대
int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (dp[0][i] < dp[0][j] + 1)
                    dp[0][i] = dp[0][j] + 1;
            }
        }
    }

    for (int i = n; i > 0; i--) {
        for (int j = n + 1; j > i; j--) {
            if (a[j] < a[i]) {
                if (dp[1][i] < dp[1][j] + 1)
                    dp[1][i] = dp[1][j] + 1;
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= n; i++) {
        if (result < dp[0][i] + dp[1][i] - 1) {
            result = dp[0][i] + dp[1][i] - 1;
        }
    }

    cout << result;

}