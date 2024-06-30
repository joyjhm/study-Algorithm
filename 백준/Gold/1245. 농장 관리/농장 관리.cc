#include <iostream>
#include <queue>

using namespace std;

int n, m;

int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int arr[100][70];
bool visited[100][70];

bool bfs(int y, int x) {

    queue<pair<int,int>> q;
    visited[y][x] = true;
    q.push({y,x});

    bool isPeak = true;

    while(!q.empty()) {

        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if(ty >= n || tx >= m || ty < 0 || tx < 0) {
                continue;
            }

            if(arr[yy][xx] == arr[ty][tx] && !visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({ty, tx});
            }
            else if(arr[yy][xx] < arr[ty][tx]) {
                isPeak = false;
            }

        }
    }

    return isPeak;
}

int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                result += bfs(i, j);
            }
        }
    }

    cout << result;

}