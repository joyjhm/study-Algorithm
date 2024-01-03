#include<iostream>
#include<algorithm>
using namespace std;

int dp[1000];
int num[1000];
int n;
int main() {

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }

    dp[0] = 1;
    for(int i = 1; i < n; i++) {
        int max_val = 1;

        for (int j = 0; j < i; j++) {
            if(num[j] < num[i]) {
                max_val = max(dp[j] + 1, max_val);
            }
        }
        dp[i] = max_val;
    }
    int result = 0;
    for(int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    cout << result;
}
