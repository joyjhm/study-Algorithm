#include <iostream>
#define mod 987654321
using namespace std;

long long dp[10001];

int main() {
    int n;
    cin >> n;

    dp[0] = 1;
    dp[2] = 1;
    dp[4] = 2;

    for (int i = 6; i <= 10000; i += 2) {
        int num = i - 2;
        for (int j = 0; j <= num; j += 2) {
            long long a = dp[num - j] % mod;
            long long b = dp[j] % mod;
            dp[i] += a * b;
            dp[i] %= mod;
        }
    }


    cout << dp[n];
}