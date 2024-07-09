#include <iostream>
#include <vector>

using namespace std;

char map[1000][1000];
int visited[1000][1000];

char dir[4] = {'R', 'D', 'L', 'U'};
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int cnt = 0;
int n, m;

void bfs(int y, int x) {

    vector<pair<int,int>> v;

    while(true) {
        int yy, xx;
        for (int i = 0; i < 4; i++) {
            if(dir[i] == map[y][x]) {
                yy = y + dy[i];
                xx = x + dx[i];
                break;
            }
        }

        if(visited[yy][xx] == 2) {
            break;
        }
        else if(visited[yy][xx] == 1) {
            cnt++;
            break;
        }

        visited[y][x] = 1;
        v.push_back({y, x});
        y = yy;
        x = xx;
    }

    for (int i = 0; i < v.size(); i++) {
        int yy = v[i].first;
        int xx = v[i].second;
        visited[yy][xx] = 2;
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    cout << cnt;
}