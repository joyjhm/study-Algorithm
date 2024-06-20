#include <iostream>
#include <vector>
using namespace std;

vector<int> connect[100001];
int sizes[100001];
bool visited[100001];


int makeTree(int cur) {

    int cnt = 0;

    for (int i = 0; i < connect[cur].size(); i++) {
        int next = connect[cur][i];
        if (!visited[next]) {
            visited[next] = true;
            cnt++;
            cnt += makeTree(next);
        }
    }

    return sizes[cur] = cnt;

}


int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    visited[r] = true;
    makeTree(r);

    for (int i = 0; i < q; i++) {
        int u;
        cin >> u;
        cout << sizes[u] + 1 << '\n';
    }
}