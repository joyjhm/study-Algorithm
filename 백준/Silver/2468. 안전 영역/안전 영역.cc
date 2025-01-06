#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int result = 1;
int max_height;
int area[100][100];
int visited[100][100][100];
int dy[4] = {0 ,1, 0, -1};
int dx[4] = {1, 0, -1, 0};
queue<pair<int,int>> q;

void bfs(int height, int i, int j) { 

    q.push({i, j});

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = yy + dy[i];
            int x = xx + dx[i];

            if(y < 0 || y >= n || x < 0 || x>= n)
                continue;
            
            if(area[y][x] > height && !visited[y][x][height]) {
                visited[y][x][height] = true;
                q.push({y, x});
            }

        }
    }
}

int main() {

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
            max_height = max(max_height, area[i][j]);
        }
    }
    
    for (int i = 1; i < max_height; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if(area[j][k] > i && !visited[j][k][i]) {
                    bfs(i, j, k);
                    cnt++;
                }
            }
        }
        result = max(result, cnt);
    }

    cout << result;
}