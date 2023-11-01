#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

bool grape[101][101];
int result[101][101];
int visited[101];
int sum[101];
int n, m;
queue<pair<int, int>> q;

void bfs(int start) {

    while(!q.empty()) {
        int node = q.front().first;
        int depth = q.front().second;
        q.pop();
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && grape[node][i]) {
                visited[i] = true;
                if(result[start][i] > depth + 1 || result[start][i] == 0) {
                    result[start][i] = depth + 1;
                }
                q.push(make_pair(i, depth + 1));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        grape[a][b] = true;
        grape[b][a] = true;
    }

    for(int i = 1; i <= n; i++) {
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        q.push(make_pair(i,0));
        bfs(i);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            sum[i] += result[i][j];
        }    
    }
    int kevin_baker = 1000000;
    int answer = 0;
    for(int i = 1; i <= n; i++) {
        if(kevin_baker > sum[i]) {
            kevin_baker = sum[i];
            answer = i;
        }
    }
    cout << answer;
}