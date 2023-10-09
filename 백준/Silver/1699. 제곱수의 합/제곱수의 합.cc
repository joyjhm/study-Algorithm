#include<iostream>
#include<cmath>
using namespace std;

int dp[100001];

int main() {
    int n;
    cin >> n;
    int max = sqrt(100000);
    for (int i = 1; i <= max; i++) {
        dp[i * i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= sqrt(i); j++) {
            if(!dp[i]) {
                dp[i] = dp[j * j] + dp[i - j * j];
            }
            else {
                dp[i] = min(dp[i], dp[j * j] + dp[i - j * j]); 
            }

        }
    }

    cout << dp[n];

}