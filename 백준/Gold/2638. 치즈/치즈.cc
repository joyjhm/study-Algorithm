#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n, m;
int cheese[100][100];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
bool visited[100][100];
int check[100][100];
queue<pair<int,int>> q;
queue<pair<int, int>> melt;
int result = -1;
int cnt = 0;


void bfs() {

    while(!q.empty()) {

        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int y = ty + dy[i];
            int x = tx + dx[i];

            if(y < 0 || y >= n || x < 0 || x >= m) {
                continue;
            }

            if(cheese[y][x] == 0 && !visited[y][x]) {
                visited[y][x] = true;
                q.push({y,x});
            }
            else if(cheese[y][x] == 1 && !visited[y][x]) {
                check[y][x]++;
                if(check[y][x] >= 2) {
                    melt.push({y,x});
                    visited[y][x] = true;
                }
            }
        }

    }
}


int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cheese[i][j];
            if(i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                q.push({i, j});
                visited[i][j]= true;
            }
        }
    }

    while(!q.empty()) {
        bfs();
        while(!melt.empty()) {
            int y = melt.front().first;
            int x = melt.front().second;
            melt.pop();

            cheese[y][x] = 0;
            q.push({y,x});
        }
        result++;

    }
    cout << result;

}