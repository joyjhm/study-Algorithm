#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
        int work_next_day = i + v[i].first;
        int not_work_next_day = i + 1;

        if(work_next_day <= n) {
            dp[work_next_day] = max(dp[work_next_day], dp[i] + v[i].second);
        }
        dp[not_work_next_day] = max(dp[i], dp[not_work_next_day]);

    }

    cout << dp[n];
}