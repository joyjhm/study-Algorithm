#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(string s)
{
    int answer = 1;
    int n = s.length();
    vector<vector<bool>> dp = vector<vector<bool>>(n, vector<bool>(n));
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        if(s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            answer = 2;
        }
    }

    for (int len = 3; len <= n; len++) {
        for (int j = 0; len + j - 1 < n; j++) {
            int r = j + len - 1;  
            if(dp[j + 1][r - 1] && s[j] == s[r]) {
                dp[j][r] = true;
                answer = len;
            }
        }
    }

    return answer;
}