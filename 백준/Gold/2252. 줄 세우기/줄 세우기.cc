#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q[32001];
bool visited[32001];

void check(int num) {

    if(visited[num]) {
        return;
    }

    while(!q[num].empty()) {
            int next = q[num].front();
            q[num].pop();
            check(next);
        }
    
    cout << num << " ";
    visited[num] = true;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        q[b].push(a);
    }

    for (int i = 1; i <= n; i++) {
        if(visited[i]) {
            continue;
        }
        check(i);
    }
}
