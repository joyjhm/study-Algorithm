#include<iostream>

using namespace std;

int number[100000];
int dp[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    dp[0] = number[0];
    for (int i = 1; i < n; i++) {

       dp[i] = max(dp[i - 1] + number[i], number[i]);
    }
    int max = dp[0];
    for (int i  = 0; i < n; i++ ) {
        if (max < dp[i]) {
            max = dp[i];
        }
    }
    cout << max;

}