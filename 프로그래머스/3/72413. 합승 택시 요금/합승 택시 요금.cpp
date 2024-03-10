#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

#define INF 100000000
using namespace std;

vector<pair<int,int>> v[201];

int result[201];

int dijkstra(int n, int target, int s, int a, int b) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    int distance[201];
    
    
    for (int i = 1; i <= n; i++) {
        if (i != target) {
            distance[i] = INF;
        } else {
            distance[i] = 0;    
        }
    }
    
    pq.push({0, target});
    
    while(!pq.empty()) {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        
        if (cost > distance[cur]) {
            continue;
        }
        
        for (int i = 0; i < v[cur].size(); i++) {
            
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;
            
            if (nextCost + cost < distance[next]) {
                distance[next] = nextCost + cost;
                pq.push({distance[next], next});
            }
        }  
    }
    
    return distance[a] + distance[b] + distance[s];
    
}

// [start, end, cost]

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    for (int i = 0; i < fares.size(); i++) {
        v[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        v[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    answer = INF;

    for (int i = 1; i <= n; i++) {
        int temp = dijkstra(n, i, s, a, b);
        answer = min(answer, temp);
        
    }
    
    return answer;
}