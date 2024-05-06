#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[300][300];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;

void bfs(int y, int x, bool visited[300][300]) {

    queue<pair<int,int>> q;
    vector<pair<int,int>> tmp;
    visited[y][x] = true;
    q.push({y, x});

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if(ty >= n || tx >= m || ty < 0 || tx < 0)
                continue;

            if(arr[ty][tx] == 0) {
                cnt++;
            }

            if(!visited[ty][tx] && arr[ty][tx] > 0) {
                visited[ty][tx] = true;
                q.push({ty, tx});
            }
            
        }

        if(arr[yy][xx] - cnt <= 0) {
            tmp.push_back({yy, xx});
        }
        else {
            arr[yy][xx] = arr[yy][xx] -  cnt;
        }
    }

    for (int i = 0; i < tmp.size(); i++) {
        int y = tmp[i].first;
        int x = tmp[i].second;
        arr[y][x] = 0;
    }
}


int main() {

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j]; 
        }
    }
    int years = 0;
    int cnt = 0;
    while(cnt <= 1) {
        cnt = 0;
        bool visited[300][300] = {false, };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j] > 0 && !visited[i][j]) {
                    bfs(i, j, visited);
                    cnt++;
                }
            }
        }
        if(cnt == 0) {
            years = 0;
            break;
        } else if (cnt > 1) {
            break;
        }
        years++;
    }

    cout << years;
}