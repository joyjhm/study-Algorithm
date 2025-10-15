#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
vector<pair<int,int>> edge[101];
int len;

int getCost(int n, int start) {
    
    int sum = 0;    
    pq.push({0, start});
    vector<bool> visited(101);

    while(!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if(visited[cur]) {
            continue;
        }
        sum += cost;
        visited[cur] = true;

        for (int i = 0; i < (int) edge[cur].size(); i++) {
            int next = edge[cur][i].first;
            int nextCost = edge[cur][i].second;
            pq.push({nextCost, next}); 
        }
    }
    
    return sum;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    len = costs.size();
    
    for (int i = 0; i < len; i++) {
        edge[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        edge[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    return getCost(0, costs[0][0]);
}