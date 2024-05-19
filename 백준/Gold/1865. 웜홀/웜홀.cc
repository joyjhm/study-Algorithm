#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <climits>
#define INF 1000000000
using namespace std;

struct Edge {
    int start;
    int dest;
    int cost;

};

int tc;
int n, m, w;
bool isPossible;

bool bfs(vector<Edge>& road) {

    vector<int> distance(n + 1, INF);

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < road.size(); j++) {
            int cur = road[j].start;
            int next = road[j].dest;
            int nextCost = road[j].cost;


            if(distance[cur] + nextCost < distance[next]) {
                distance[next] = distance[cur] + nextCost;
            }
        }
    }

    for (int i = 0; i < road.size(); i++) {
        int cur = road[i].start;
        int next = road[i].dest;
        int nextCost = road[i].cost;

        if(distance[cur] + nextCost < distance[next]) {
            return true;
        } 
    }

    return false;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while(tc--) {
        cin >> n >> m >> w;

        vector<Edge> road;
        vector<bool> visited(n + 1);
        for (int i = 0; i < m; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            road.push_back({s, e, t});
            road.push_back({e, s, t});

        }

        for (int i = 0; i < w; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            road.push_back({s, e, -t});
        }


        isPossible = bfs(road);

        if(isPossible) {
            cout << "YES" << '\n';
        }
        else {
            cout << "NO" << '\n';
        }
    }
}


