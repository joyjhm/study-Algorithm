#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int dp[50001];

int main() {
    int n;
    cin >> n;
    std::fill_n(dp, 50001, 5);
    for(int i = 1; i < 224; i++) {
        dp[i * i] = 1;
    }
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(dp[i] == 1) {
            continue;
        }
        int num;
        int index = 1;
        while(index * index < i) {
            num = index * index;
            index +=1;
            dp[i] = min(dp[i],dp[num] + dp[i - num]);
        }
    }

    cout << dp[n];
}