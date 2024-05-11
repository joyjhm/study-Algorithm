#include <iostream>
#include <vector>
using namespace std;

vector<int> rel[2000];
bool result;
bool visited[2000];
void dfs(int idx, int depth) {

    if(result) {
        return;
    }

    if (depth == 5) {
        result = true;
        return;
    }

    for (int i = 0; i < rel[idx].size(); i++) {
        int next = rel[idx][i];
        if(!visited[next]) {
            visited[next] = true;
            dfs(next, depth + 1);
            visited[next] = false;
        }
    }
}


int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, 0);
    }

    if(result) {
        cout << 1;
    } else {
        cout << 0;
    }

}

