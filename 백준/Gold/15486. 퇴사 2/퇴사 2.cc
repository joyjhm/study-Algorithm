#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int result = 0;
int dp[1500001];
vector<pair<int,int>> v(1500001);

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t, p;
        cin >> t >> p;
        v[i].first = t;
        v[i].second = p;
    }

    
    for (int i = 0; i < n; i++) {
        int day1 = i + v[i].first;
        int day2 = i + 1;

        if(day1 <= n) {
            dp[day1] = max(dp[day1], dp[i] + v[i].second);
        }
        dp[i + 1] = max(dp[i], dp[i + 1]);

    }

    cout << dp[n];
}