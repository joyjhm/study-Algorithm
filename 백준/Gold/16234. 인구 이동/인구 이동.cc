#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int n, l, r;
int a[50][50];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

int bfs(int y, int x, bool visited[50][50]) {
    bool uni = false;
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;
    vector<pair<int, int>> v;
    v.push_back({y, x});
    int num = a[y][x];
    while(!q.empty()) {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();

        for (int i = 0 ; i < 4; i++) {
            y = ty + dy[i];
            x = tx + dx[i];

            if(y >= n || x >= n || y < 0 || x < 0) 
                continue;
            int tmp = abs(a[ty][tx] - a[y][x]);

            if(!visited[y][x] && tmp >= l && tmp <= r) {
                q.push({y, x});
                visited[y][x] = true;
                v.push_back({y, x});
                uni = true;
                num += a[y][x];
            }

        }
    }

    if (uni) {
        for (int i = 0; i < v.size(); i++) {
            int ty = v[i].first;
            int tx = v[i].second;
            a[ty][tx] = num / v.size();
        }
        return v.size();
    } else {
        return 0;
    }

}

int main() {

    cin >> n >> l >> r;
    int cnt = 1;
    int days = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while(cnt != 0) {

        cnt = 0;
        bool visited[50][50] = {false, };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(!visited[i][j]) {
                    cnt += bfs(i, j, visited);
                }
            }
        }

        if(cnt) {
            days++;
        }
    }

    cout << days;


}