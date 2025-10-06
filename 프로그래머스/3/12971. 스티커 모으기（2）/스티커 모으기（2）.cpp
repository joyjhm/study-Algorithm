#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    vector<int> dp(n);
    vector<int> dp2(n);
    
    if(n == 1) {
        return sticker[0];
    }

    dp[0] = sticker[0];
    dp[1] = max(sticker[0], sticker[1]);

    dp2[1] = sticker[1];
    dp2[2] = max(sticker[1], sticker[2]);
    for (int i = 2; i < n - 1; i++) {
        dp[i] = max((dp[i - 2] + sticker[i]), dp[i - 1]);    
    }

    for (int i = 3; i < n; i++) {
        dp2[i] = max((dp2[i - 2] + sticker[i]), dp2[i - 1]);  
    }

    for (int i = 0; i < n; i++) {
        answer = max({answer, dp[i], dp2[i]});
    }

    return answer;
}