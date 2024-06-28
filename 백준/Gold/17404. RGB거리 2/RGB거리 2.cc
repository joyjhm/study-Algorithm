#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][3][3];
int arr[1001][3];

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int j = 0; j < 3; j++) {
        for (int i = 1; i <= n - 1; i++) {
            if(i == 1) {
                dp[1][j][j] = arr[i][j];
                dp[1][(j + 1) % 3][j] = 10000000;
                dp[1][(j + 2) % 3][j] = 10000000;
            }
            else if (i == 2) {
                for (int k = 0; k < 3; k++) {
                    if(k == j) {
                        dp[2][k][j] = 10000000;
                    }
                    else {
                        dp[2][k][j] = arr[1][j] + arr[2][k];
                    }
                }
            }
            else {
                dp[i][0][j] = arr[i][0] + min(dp[i - 1][1][j], dp[i - 1][2][j]);
                dp[i][1][j] = arr[i][1] + min(dp[i - 1][0][j], dp[i - 1][2][j]);
                dp[i][2][j] = arr[i][2] + min(dp[i - 1][0][j], dp[i - 1][1][j]);
            }  
        }

        for (int k = 0; k < 3; k++) {
            if(k == j) {
                dp[n][k][j] = min(arr[n][(k + 1) % 3], arr[n][(k + 2) % 3]) + dp[n - 1][k][j];
            } else {
                dp[n][k][j] = arr[n][3 - j - k] + dp[n - 1][k][j];
            }

        }
    }

    int result = 10000000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result = min (result, dp[n][i][j]);
        }
    }


    cout << result;
}