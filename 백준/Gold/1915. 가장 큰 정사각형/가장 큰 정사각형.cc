#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char num;
            cin >> num;
            arr[i][j] = num - '0';
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = arr[i][j];
                answer = max(answer, dp[i][j]);
            }
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if(arr[i][j]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
            else {
                dp[i][j] = 0;
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer * answer;
}