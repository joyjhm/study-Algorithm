#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int x;
    int y;
    int cnt;
};

bool visited[101][101];
int dy[8] = {-1,-2,2,1,-1,-2,1,2};
int dx[8] = {2,1,-1,-2,-2,-1,2,1};
int n, m, y, x;

int bfs() {

    queue<Point> q;

    q.push({1,1,0});
    visited[1][1]= true;

    while(!q.empty()) {
        int xx = q.front().x;
        int yy = q.front().y;
        int cnt = q.front().cnt;
        q.pop();

        if(x == xx && y == yy) {
            return cnt;
        }

        for (int i = 0; i < 8; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if (ty > m || tx > n || ty <= 0 || tx <= 0)
                continue;

            if(!visited[tx][ty]) {
                visited[tx][ty] = true;
                q.push({tx, ty, cnt + 1});
            }
        }
    }

    return 0;
}


int main() {

    cin >> n >> m >> x >> y;

    int result = bfs();

    if (result) {
        cout << result;
    } else {
        cout << "NEVAR";
    }

}