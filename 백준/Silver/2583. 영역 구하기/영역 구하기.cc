#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, k;
bool board[101][101];

queue<pair<int,int>> q;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<int> v;


int bfs(int start_x, int start_y) {

    int cnt = 0;

    q.push({start_x, start_y});
    board[start_x][start_y] = true;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(yy < 0 || yy >= m || xx < 0 || xx >= n)
                continue;

            if(!board[xx][yy]) {
                q.push({xx, yy});
                board[xx][yy] = true;
            }
        }
    }

    return cnt;
}

void drawRectangle(int x1, int y1, int x2, int y2) {

    for (int i = x1; i < x2; i++) {
        for (int j = y1; j < y2; j++) {
            board[i][j] = true;
        }
    }
}


int main() {

    cin >> m >> n >> k;

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        drawRectangle(x1, y1, x2, y2);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!board[i][j]) {
                int cnt = bfs(i, j);
                v.push_back(cnt);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << '\n';

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';

    }
}