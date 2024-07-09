#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int candy[30001];
vector<int> rel[30001];
int n, m, k;
bool visited[30001];
int cnt;
int dp[30001][3001];

int bfs(int idx) {

    queue<int> q;
    q.push(idx);
    int sum = candy[idx];
    cnt = 1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < rel[cur].size(); i++) {
            int next = rel[cur][i];
            if(!visited[next]) {
                cnt++;
                sum += candy[next];
                visited[next] = true;
                q.push(next);
            }
        }
    }

    return sum;
}

int main() {

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
    }

    for (int i = 0; i < m; i++) {
        int kid1, kid2;
        cin >> kid1 >> kid2;
        rel[kid1].push_back(kid2);
        rel[kid2].push_back(kid1);
    }

    vector<pair<int,int>> greedy;

    for (int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            int sum = bfs(i);
            greedy.push_back({sum, cnt});
        }
    }



    int g = greedy.size();

    for (int i = 0; i < g; i++) {
        for (int j = 1; j < k; j++) {
            if(i > 0 && dp[i - 1][j]) {
                if (j + greedy[i].second < k) {
                    dp[i][j + greedy[i].second] = max(dp[i][j + greedy[i].second], dp[i - 1][j] + greedy[i].first);
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }

        if(greedy[i].second < k) {
            dp[i][greedy[i].second] = max(dp[i][greedy[i].second], greedy[i].first);
        }
    }

    int result = 0;

    for (int i = 0; i < k; i++) {
        result = max(result, dp[g - 1][i]);
    }

    cout << result;

    
}