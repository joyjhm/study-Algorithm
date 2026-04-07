#include <string>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(), money.end());
    vector<int> dp = vector<int>(n + 1);
    

    for (int i = 0; i < money.size(); i++) {
        int target = money[i];
        dp[target] += 1;
        for (int j = target; j <= n; j++) {
            dp[j] = (dp[j] + dp[j - target]) % MOD;
        }        
    }

    return dp[n];
}