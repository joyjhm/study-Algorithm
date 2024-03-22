#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> distance(n + 1, 20001);
    vector<int> v[n + 1];
    for (int i = 0; i < edge.size(); i++) {
        int start = edge[i][0];
        int dest = edge[i][1];
        v[start].push_back(dest);
        v[dest].push_back(start);
    }
    
    pq.push({0, 1});
    distance[1] = 0;
    while(!pq.empty()) {
        int cnt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for (int i = 0; i < v[node].size(); i++) {
            int next = v[node][i];
            if (1 + cnt < distance[next]) {
                distance[next] = cnt + 1;
                pq.push({cnt + 1, next});
            }
        }
    }
    int max_val = 0;
    
    for (int i = 1; i < distance.size(); i++) {
        if(max_val < distance[i]) {
            max_val = distance[i];
            answer = 1;
        } else if(max_val == distance[i]) {
            answer++;
        }
    }
    
    return answer;  
    
}