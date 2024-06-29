#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000
using namespace std;

int arr[1001][3];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 10000000;

    for (int j = 0; j < 3; j++) {
        int dp[1001][3];

        for (int i = 0; i < 3; i++) {
            if(j == i) {
                dp[1][i] = arr[1][i];
            }
            else {
                dp[1][i] = INF;
            }
        }

        for (int i = 2; i <= n; i++) {

            dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
            dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
            
        }

        for (int i = 0; i < 3; i++) {
            if(i == j) {
                continue;
            } else {
                result = min(result, dp[n][i]);
            }
        }
    }

    cout << result;

}