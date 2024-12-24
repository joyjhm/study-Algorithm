#include <iostream>
#include <cstring>

using namespace std;


int dp[5000];
int mod = 1000000;

int main() {

    string str;
    cin >> str;

    dp[0] = 1;
    dp[1] = 1;

    if(str[0] == '0') {
        cout << 0;
        return 0;
    }

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == '0' && (str[i - 1] == '1' || str[i - 1] == '2')) {
            dp[i + 1] = dp[i - 1] % mod;
        } 
        else if (str[i] == '0' && (str[i - 1] == '0' || str[i - 1] >= '3')) {
            cout << 0;
            return 0;
        }
        else if ((str[i - 1] == '2' && str[i] <= '6') || str[i - 1] == '1') {
            dp[i + 1] = (dp[i] + dp[i - 1]) % mod;
        }
        else {
            dp[i + 1] = dp[i] % mod;
        }

    }

    cout << dp[str.length()];

}