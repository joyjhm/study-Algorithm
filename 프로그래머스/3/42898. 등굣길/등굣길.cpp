#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<bool>> road(n + 1, vector<bool>(m + 1));
    
    for (int i = 0; i < puddles.size(); i++) {
        road[puddles[i][1]][puddles[i][0]] = true;
    }
    
    
    for (int i = 1; i <= n; i++) {
        if(road[i][1]) {
            break;
        }
        dp[i][1] = 1;
    }
    
    for (int j = 1; j <= m; j++) {
        if(road[1][j]) {
            break;
        }
        dp[1][j] = 1;
    }
    
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            if(road[i][j]) {
                dp[i][j] = 0;
                continue;
            }
                        
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % 1000000007;
            
        }
    }
    
    answer = dp[n][m];
    
    return answer;
}