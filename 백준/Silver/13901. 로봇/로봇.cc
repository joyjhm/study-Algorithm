#include <iostream>
#include <vector>
#include <queue>
using namespace std;


bool visited[1000][1000];
vector<int> dir(4);
int sr, sc;
int r, c;

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};
void move() {

    queue<pair<int,int>> q;
    q.push({sr, sc});
    int y, x;
    int idx = 0;
    visited[sr][sc] = true;

    while(!q.empty()) {
        
        y = q.front().first;
        x = q.front().second;
        q.pop();
        int ty, tx;

        for (int i = 0; i < 4; i++) {

            ty = y + dy[dir[idx]];
            tx = x + dx[dir[idx]];

            if (ty >= r || tx >= c || ty < 0 || tx < 0 || visited[ty][tx]) {
                idx++;
                if(idx == 4) {
                    idx = 0;
                }
                continue;
            }

            if (!visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({ty, tx});
                break;
            }
            
        }
    }

    sr = y;
    sc = x;
}

int main() {

    cin >> r >> c;

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int br, bc;
        cin >> br >> bc;
        visited[br][bc] = true;
    }

    cin >> sr >> sc;

    for (int i = 0; i < 4; i++) {
        int tmp;
        cin >> tmp;
        dir[i] = tmp;
    }

    move();

    cout << sr << " " << sc;
}