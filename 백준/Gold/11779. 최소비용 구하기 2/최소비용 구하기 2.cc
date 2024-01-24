#include<iostream>
#include<queue>
#define INF 100000000
using namespace std;

int n, m;
vector<pair<int, int>> v[1001]; // {end, cost}
int start, dest, cost;
int result[1001];
int previous[1001];
vector<int> course;
priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;


void dijkstra(int s, int d) {

    pq.push({0, s});
    result[start] = 0;

    while(!pq.empty()) {
        int cost= pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cost > result[d]) {
            continue;
        }

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextCost = v[cur][i].second;

            if (nextCost + cost < result[next]){
                result[next] = nextCost + cost;
                previous[next] = cur;
                pq.push({nextCost + cost, next});
            }
        }

    }

    course.push_back(dest);
}




int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> start >> dest >> cost;
        v[start].push_back({dest,cost});
    }

    cin >> start >> dest;

    for(int i = 1; i <= n; i++) {
        result[i] = INF;
    }

    dijkstra(start, dest);

    cout << result[dest] << '\n';
    int tmp = dest;
    while(tmp != start) {
        tmp = previous[tmp];
        course.push_back(tmp);
    }


    cout << course.size() << '\n';
    while(!course.empty()) {
        cout << course.back() << " ";
        course.pop_back();
    }

}