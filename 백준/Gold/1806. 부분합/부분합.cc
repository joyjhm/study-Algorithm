#include <iostream>
#include <vector>
#include <algorithm>
#define INF 100001
using namespace std;

int dp[100000][2];  // cnt, value

int main() {
    int n, s;
    cin >> n >> s;
    vector<int> arr(n);
    int result = INF;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][1] = arr[0];
    dp[0][0] = 1;

    if (dp[0][1] >= s) {
        result = dp[0][0];
    }

    for (int i = 1; i < n; i++) {
        if(arr[i] + dp[i - 1][1] < s) {
            dp[i][1] = arr[i] + dp[i - 1][1];
            dp[i][0] = dp[i - 1][0] + 1;
        } else {
            dp[i][1] = arr[i] + dp[i - 1][1];
            dp[i][0] = dp[i - 1][0] + 1;
            int cnt = dp[i][0];
            while(dp[i][1] - arr[i - cnt + 1] >= s) {
                dp[i][1] -= arr[i - cnt + 1];
                cnt--;
            }
            dp[i][0] = cnt;
            result = min(result, cnt);
        }
    }

    if (result == INF) {
        cout << 0;
    } else {
        cout << result;
    }


}