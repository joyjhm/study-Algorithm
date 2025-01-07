#include <iostream>
#include <queue>
using namespace std;

int start_y, start_x;
int dist_y, dist_x;
int board[300][300];
int l;
int dy[8] = {2,1,-1,-2,-2,-1,1,2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int cnt;

int bfs() {

    queue<pair<int,int>> q;
    q.push({start_y, start_x});
    board[start_y][start_x] = 1;
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        cnt = board[y][x];
        q.pop();

        if(y == dist_y && x == dist_x) {
            return cnt - 1;
        }

        for (int i = 0; i < 8; i++) {
            int yy = dy[i] + y;
            int xx = dx[i] + x;
            if(yy >= l || yy < 0 || xx >= l || xx < 0)
                continue;

            if(board[yy][xx] < board[y][x] + 1) {
                q.push({yy, xx});
                board[yy][xx] = board[y][x] + 1;
            }
        }
    }

    return cnt;
}


int main() {

    int t;
    cin >> t;

    while(t--) {
        cin >> l;
        cin >> start_y >> start_x;
        cin >> dist_y >> dist_x;

        int result = bfs();
        cout << result << '\n';


        for (int i = 0; i < l; i++) {
            for (int j = 1; j < l; j++) {
                board[i][j] = 0;
            }
        }
    }

}