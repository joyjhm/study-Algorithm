#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

int n, m;
int arr[1000][1000];
int result[1000][1000];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
queue<pair<int, int>> q;

void bfs(int x, int y) {

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(x < 0 || x >= m || y < 0 || y >= n){
                continue;
            }
            if(result[ny][nx] == 0 && arr[ny][nx] != 0) {
                q.push(make_pair(ny,nx));
                result[ny][nx] = result[y][x] + 1;
            }
        }
    }
}

int main() {
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2){
                y = i;
                x = j;
            }
        }
    }
    q.push(make_pair(y,x));
    bfs(x,y);
    result[y][x] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){ 
            if(arr[i][j] == 1 && result[i][j] == 0) {
                result[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){ 
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}