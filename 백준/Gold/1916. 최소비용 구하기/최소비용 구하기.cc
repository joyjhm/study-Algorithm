#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int n, m;
vector<pair<int, int>> city[1001];
vector<bool> visited[1001];
int start, dest, cost;
priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
int result[1001];
int main() {

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> start >> dest >> cost;

        city[start].push_back({cost, dest});
        visited[start].push_back(false);
    }

    cin >> start >> dest;

    for(int i = 1; i <= n; i++) {
        if (i == start) {
            result[i] = 0;
            continue;
        }
        result[i] = 1000000001;
    }

    pq.push({0, start});

    while(!pq.empty()) {
        int distance = pq.top().first;
        int current = pq.top().second;

        pq.pop();
        if(result[current] < distance)
            continue;

        for(int i = 0; i < city[current].size(); i++) {
            int next = city[current][i].second;
            int nextDistance = distance + city[current][i].first;
            if(nextDistance < result[next]) {
                result[next] = nextDistance;
                pq.push({nextDistance, next});
            }
        }
        
    }

    cout << result[dest];

}