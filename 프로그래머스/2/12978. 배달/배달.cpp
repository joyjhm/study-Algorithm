#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;


vector<pair<int,int>> v[51];

vector<int> dijkstra(int n) {
    vector<int> distance(n + 1, INF);
    distance[1] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1});    

    while(!pq.empty()) {
        int cost = pq.top().first;        
        int cur = pq.top().second;
        pq.pop();
        

        if(cost > distance[cur]) {
            continue;
        }

        
        for (int i = 0; i < v[cur].size(); i++) {
            int nextCost = v[cur][i].second;
            int next = v[cur][i].first;

            if(distance[next] > nextCost + distance[cur]) {
                distance[next] = nextCost + distance[cur];
                pq.push({nextCost + distance[cur], next});
            }
        }   
    }
    
    return distance;
}


int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int m = road.size();
    
    for (int i = 0; i < m; i++) {
        int start = road[i][0];
        int end = road[i][1];
        int val = road[i][2];
        v[start].push_back({end, val});
        v[end].push_back({start, val});
    }
    
    vector<int> distance = dijkstra(N);

    for (int i = 1; i <= N; i++) {
        if(distance[i] <= K) {
            answer++;
        }
    }

    return answer;
}