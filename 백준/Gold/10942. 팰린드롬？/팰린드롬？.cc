#include <iostream>
#include <vector>
using namespace std;

bool dp[2001][2001];


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        dp[i][i] = true;
    }

    for (int i = 1; i <= n - 1; i++) {
        for (int j = i + 1; j <= n; j++) {
            if(arr[j] == arr[j - i]) {
                if(i <= 1) {
                    dp[j - i][j] = true;
                }

                else if(dp[j - i + 1][j - 1]) {
                    dp[j - i][j] = true;
                }
            }
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << dp[s][e] << '\n';

    }

}