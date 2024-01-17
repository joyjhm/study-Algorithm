#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
bool visited[500][500];
int paper[500][500];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int max_draw = 0;

void bfs() {

    int draw_size = 1;    
    while(!q.empty()) {

        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = dy[i] + ty;
            int x = dx[i] + tx;

            if (y < 0 || y >= n || x < 0 || x >= m)
                continue;
            
            if(!visited[y][x] && paper[y][x] == 1) {
                draw_size++;
                visited[y][x] = true;
                q.push({y,x});
            }
            
        }
    }

    max_draw = max(draw_size, max_draw);
}

int main() {

    cin >> n >> m;
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j] && paper[i][j] == 1) {
                cnt++;
                visited[i][j] = true;
                q.push({i, j});
                bfs();
            }
        }
    }

    cout << cnt << '\n';
    cout << max_draw;
}