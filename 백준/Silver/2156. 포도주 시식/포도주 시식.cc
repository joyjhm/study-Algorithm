#include<iostream>

using namespace std;

int cups[10001];
int dp[10001];

int main() {

    int n, cup;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> cup;
        cups[i] = cup;
    }

    dp[1] = cups[1];
    dp[2] = cups[1] + cups[2];

    for (int i = 1; i <= n; i++) {
        dp[i] = max(max(dp[i - 2] + cups[i], dp[i - 3] + cups[i - 1] + cups[i]), dp[i - 1]);
    }

    cout << dp[n];
}