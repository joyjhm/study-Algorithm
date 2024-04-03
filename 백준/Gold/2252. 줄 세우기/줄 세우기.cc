#include <iostream>
#include <queue>
using namespace std;

int n, m;
queue<int> q[32001];
bool visited[32001];


void go(int num) {

    if(visited[num]) {
        return;
    }

    if(!q[num].empty()) {
        while(!q[num].empty()) {
            int next = q[num].front();
            q[num].pop();
            go(next);
        }
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

        go(i);
        
    }
}