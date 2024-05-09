#include <iostream>
#include <queue>
#include <vector>
using namespace std;



int main() {
    int n, m;
    cin >> n;
    cin >> m;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<pair<int,int>> line[n + 1];
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }

    int result = 0;
    pq.push({0, 1});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(visited[cur])
            continue;
        visited[cur] = true;
        result += cost;

        for (int i = 0; i < line[cur].size(); i++) {
 
            int next = line[cur][i].first;
            int nextCost = line[cur][i].second;   
            pq.push({nextCost, next});
            
        }
    }

    cout << result;

}
  