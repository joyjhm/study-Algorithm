#include<iostream>
#include<queue>
using namespace std;

char campus[600][600];
int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visited[600][600];
queue<pair<int, int>> q;

int bfs(int x, int y) {
    int cnt = 0;
    q.push(make_pair(y,x));
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if(ny < 0 || ny >= n || nx < 0 || nx >= m){
                continue;
            }
            if(!visited[ny][nx] && campus[ny][nx] != 'X') {
                visited[ny][nx] = true;
                q.push(make_pair(ny, nx));
                if(campus[ny][nx] == 'P') {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


int main() {
    cin >> n >> m;
    int x, y;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> campus[i][j];
            if(campus[i][j] == 'I') {
                y = i;
                x = j;
            }
        }
    }

    int result = bfs(x, y);
    if(result == 0) {
        cout << "TT";
    }
    else {
        cout << result;
    }
}