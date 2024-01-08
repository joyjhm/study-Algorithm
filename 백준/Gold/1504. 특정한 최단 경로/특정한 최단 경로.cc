#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int n, e;
vector<pair<int, int>> node[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
int v1, v2;
int result[4][801];

void dijkstra(int start, int idx) {

    pq.push({0,start});
    result[idx][start] = 0;

    while(!pq.empty()) {
        int distance = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < node[cur].size(); i++) {
            int next = node[cur][i].first;
            int nextDistance = node[cur][i].second;
            if(result[idx][next] > distance + nextDistance) {
                result[idx][next] = distance + nextDistance;
                pq.push({distance + nextDistance, next});
            }
        }

    }

}

int main() {
    cin >> n >> e;

    for(int i = 0; i < e; i++) {
        int to, from, cost;
        cin >> to >> from >> cost;
        node[to].push_back({from, cost});
        node[from].push_back({to, cost});

    }
    cin >> v1 >> v2;

    for(int i = 0; i < 4; i++) {
        for(int j = 1; j <= n; j++) {
            result[i][j] = 100000000;
        }
    }

    dijkstra(1, 0);
    dijkstra(v1, 1); 
    dijkstra(v2, 2);

    int answer = min(result[0][v1] + result[1][v2] + result[2][n], result[0][v2] + result[2][v1] + result[1][n]);

    if (answer >= 100000000) {
        cout << -1;
    } else {
        cout << answer;
    }


}