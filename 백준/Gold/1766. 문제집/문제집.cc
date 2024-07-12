#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> line[32001];
int visited[32001];
int connect[32001];
vector<int> result;

int main() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        line[a].push_back(b);
        connect[b]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 1; i <= n; i++) {
        if(!visited[i] && connect[i] == 0) {
            pq.push(i);
        }
    }

    while(!pq.empty()) {
        int cur = pq.top();
        result.push_back(cur);
        pq.pop();

        for (int i = 0; i < line[cur].size(); i++) {
            int next = line[cur][i];
            if (--connect[next] == 0) {
                pq.push(next);
            }
        }

    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }

}