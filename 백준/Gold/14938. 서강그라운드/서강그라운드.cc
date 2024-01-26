#include<iostream>
#include<queue>
#include<cstring>
#define INF 100000000
using namespace std;

int item[101];
int n, m, r;
vector<pair<int,int>> road[101];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int result = 0;

int dijkstra(int start) {
    int cnt = 0;
    int dist[101];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < road[cur].size(); i++) {
            int next = road[cur][i].first;
            int nextDist = road[cur][i].second;

            if(cost + nextDist < dist[next]) {
                dist[next] = cost + nextDist;
                pq.push({cost + nextDist, next});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if(dist[i] <= m) {
            cnt += item[i];
        }
    }
    return cnt;
}

int main() {

    cin >> n >> m >> r;
    
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    int a, b, l;

    for (int i = 0; i < r; i++) {
        cin >> a >> b >> l;
        road[a].push_back({b,l});
        road[b].push_back({a,l});
    }

    for (int i = 1; i <= n; i++) {
        pq.push({0, i});
        result = max(dijkstra(i), result);
    }

    cout << result;
}