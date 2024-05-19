#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v;
vector<pair<int,int>> line[100001];
int result = 0;
bool visited[100001];
int node;

void dfs(int idx, int val) {

    if(result < val) {
        result = val;
        node = idx;
    }

    for (int i = 0; i < line[idx].size(); i++) {
        int next = line[idx][i].first;
        int nextCost = line[idx][i].second;

        if(!visited[next]) {
            visited[next] = true;
            dfs(next, nextCost + val);
            visited[next] = false;
        }
    }
}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> v;

    for (int i = 1; i <= v; i++) {
        int start;
        cin >> start;
        while(true) {
            int dest, cost;
            cin >> dest;
            if(dest == -1) {
                break;
            }
            cin >> cost;
            line[start].push_back({dest, cost});
        }
    }



    visited[1] = true;
    dfs(1, 0);
    visited[1] = false;

    visited[node] = true;
    dfs(node, 0);
    visited[node] = false;
    
    cout << result;

}
