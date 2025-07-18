#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int len = land.size();
    vector<vector<int>> dp(len, vector<int>(4));

    dp[0][0] = land[0][0];
    dp[0][1] = land[0][1];
    dp[0][2] = land[0][2];
    dp[0][3] = land[0][3];
    
    for (int i = 1; i < len; i++) {
        dp[i][0] = land[i][0] + max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}); 
        dp[i][1] = land[i][1] + max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]}); 
        dp[i][2] = land[i][2] + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]}); 
        dp[i][3] = land[i][3] + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}); 

    }
    
    answer = max({dp[len - 1][0], dp[len - 1][1], dp[len - 1][2], dp[len - 1][3]});
    
    return answer;
}