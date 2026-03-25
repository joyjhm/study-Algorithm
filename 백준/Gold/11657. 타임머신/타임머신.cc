#include <iostream>
#include <vector>
#define INF 1e18
using namespace std;

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int,int>> node[n + 1];

    for (int i = 0; i < m; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        node[start].push_back({end, cost});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < node[j].size(); k++) {
                int target = node[j][k].first;
                int cost = node[j][k].second;
                if(dist[j] != INF && dist[j] + cost < dist[target]) {
                    dist[target] = dist[j] + cost;
                }
            } 
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < node[i].size(); j++) {
            int target = node[i][j].first;
            int cost = node[i][j].second;          
            if(dist[i] != INF && dist[i] + cost < dist[target]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }


    for (int i = 2; i <= n; i++) {
        if(dist[i] == INF) {
            cout << -1 << '\n';
        }
        else {
            cout << dist[i] << '\n';
        }
    }
}