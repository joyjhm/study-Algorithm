#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k, dest;
        cin >> n >> k;
        vector<int> d(n + 1);
        queue<int> line[n + 1];
        vector<int> cnt(n + 1);
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
        }

        for (int i = 0; i < k; i++) {
            int start, dest;
            cin >> start >> dest;
            line[start].push(dest);
            cnt[dest]++;
        }
        cin >> dest;

        queue<pair<int,int>> q;
        
        for (int i = 1; i <= n; i++) {
            if(cnt[i] == 0) {
                q.push({i, 0});
            }
        }

        int result;
        while(!q.empty()) {
            int cur = q.front().first;
            int cost = q.front().second;
            q.pop();
            cost += d[cur];
            if (cur == dest) {
                result = cost;
                break;
            }

            while(!line[cur].empty()) {
                int next = line[cur].front();
                line[cur].pop();
                cnt[next]--;
                dp[next] = max(dp[next], cost);
                if (cnt[next] == 0) {
                    q.push({next, dp[next]});
                }
            }  
        }

        cout << result << '\n';

    }


}    