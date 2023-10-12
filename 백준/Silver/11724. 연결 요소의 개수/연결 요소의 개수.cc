#include<iostream>
#include<queue>

using namespace std;

int n,m;
int node[1001][1001];
bool visited[1001];
queue<int> q;

void bfs() {
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(node[x][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

    }
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        node[a][b] = 1;
        node[b][a] = 1;
    }

    int result = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]){
            q.push(i);
            visited[i] = true;
            bfs();
            result++;
        }
    }
    cout << result;

    
}