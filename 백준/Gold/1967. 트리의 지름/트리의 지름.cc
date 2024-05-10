#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> line[10001];
bool visited[10001];
int result = 0;
int n;

void dfs(int idx,int cost) {

    if (result < cost) {
        result = cost;
    }

    for (int i = 0; i < line[idx].size(); i++) {
        int next = line[idx][i].first;
        int nextCost = line [idx][i].second;

        if(!visited[next]) {
            visited[next] = true;
            dfs(next, nextCost + cost);
            visited[next] = false;
        }
    }

}

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        line[a].push_back({b, c});
        line[b].push_back({a, c});
    }

    for (int i = 1; i <= n; i++) {
        visited[i] = true;
        dfs(i, 0);
        visited[i] = false;
    }

    cout << result;

}