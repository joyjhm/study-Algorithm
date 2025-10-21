#include <string>
#include <vector>
#include <queue>
#define INF 500000
using namespace std;

vector<int> edge[100001];

vector<int> dijkstra(int n, int dest, vector<int>& sources) {
    
    vector<int> distance(n + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    distance[dest] = 0;
    pq.push({0, dest});

    while(!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(distance[cur] < cost) {
            continue;
        }

        for (int i = 0; i < edge[cur].size(); i++) {
            int next = edge[cur][i];
            if(distance[cur] + 1 < distance[next]) {
                pq.push({cost + 1, next});
                distance[next] = cost + 1;
            }
        }
    }
    
    return distance;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;

    for (int i = 0; i < roads.size(); i++) {
        edge[roads[i][0]].push_back(roads[i][1]);
        edge[roads[i][1]].push_back(roads[i][0]);
    }    

    vector<int> distance = dijkstra(n, destination, sources);    

    for (int i = 0; i < sources.size(); i++) {
        if(distance[sources[i]] == INF) {
            answer.push_back(-1);
        } else {
            answer.push_back(distance[sources[i]]);
        }
    }

    return answer;
}