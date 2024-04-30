#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maps[100][100];
bool visited[100][100];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n;
vector<vector<pair<int,int>>> v;


void bfs(int y, int x) {

    queue<pair<int,int>> q;
    vector<pair<int,int>> tmp;
    q.push({y, x});

    while(!q.empty()) {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            y = ty + dy[i];
            x = tx + dx[i];
            
            if (y < 0 || x < 0 || y >= n || x >= n) {
                cnt++;
                continue;
            }

            if(maps[y][x]) {
                cnt++;
                if(!visited[y][x]) {
                    visited[y][x] = true;
                    q.push({y, x});
                }
            }
        }

        if (cnt < 4) {
            tmp.push_back({ty, tx});
        }
    }


    v.push_back(tmp);
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maps[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!visited[i][j] && maps[i][j] == 1) {
                visited[i][j] = true;
                bfs(i, j);
            }
        }
    }

    int result = 100000000;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {

            for (int y = i + 1; y < v.size(); y++) {
                for (int x = 0; x < v[y].size(); x++) {
                    int y1 = v[i][j].first;
                    int x1 = v[i][j].second;

                    int y2 = v[y][x].first;
                    int x2 = v[y][x].second;

                    result = min(result, abs(y1 - y2) + abs(x1 - x2) - 1);
                }
            }
        }
    }

    cout << result;
}
