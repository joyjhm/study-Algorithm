// 다익스트라 2번만 사용해서 풀어보기

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int n, m, x;
vector<pair<int,int>> node[1001];   //{dist, cost}
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;   // {cost, start}
int result[1001][1001];


void dijkstra(int start) {


    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < node[cur].size(); i++) {

            int next = node[cur][i].first;
            int nextCost = node[cur][i].second;

            if(nextCost + cost < result[start][next]) {
                result[start][next] = nextCost + cost;
                pq.push({nextCost + cost, next});
            }
        }

        
    }
}

int main() {
    
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int start, dist, cost;
        cin >> start >> dist >> cost;
        node[start].push_back({dist, cost});
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(i == j) {
                continue;
            }
            result[i][j] = INT32_MAX;
        }
    }

    for(int i = 1; i <= n; i++) {
        pq.push({0,i});
        dijkstra(i);
    }

    int answer = 0;

    for(int i = 1; i <= n; i++) {
        answer = max(result[i][x] + result[x][i], answer);
    }

    cout << answer;

}
