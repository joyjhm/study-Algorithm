#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        dp[i].push_back(arr[i]);

        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                if(dp[i].size() < dp[j].size() + 1) {
                    dp[i] = dp[j];
                    dp[i].push_back(arr[i]);

                }
                // dp[i] = max(dp[i], dp[j] + 1);
            }
        };

        if(dp[i].size() > result) {
            result = dp[i].size();
            idx = i;
        }

    }

    cout << result << '\n';
    for (int i = 0; i < dp[idx].size(); i++) {
        cout << dp[idx][i] << " ";
    }
}