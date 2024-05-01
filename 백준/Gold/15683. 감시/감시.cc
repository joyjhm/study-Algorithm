#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int maps[8][8];
vector<pair<int,int>> cctv;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int result = 100;

int check() {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(maps[i][j] == 0)
                cnt++;
        }
    }

    return cnt;
}

void monitor(vector<int> dir, int y, int x) {

    for (int i = 0; i < dir.size(); i++) {
        int d = dir[i];
        int ty = y + dy[d];
        int tx = x + dx[d];

        while(ty < n && tx < m && tx >= 0 && ty >= 0) {
            if(maps[ty][tx] == 6) {
                break;
            }
            else if(maps[ty][tx] <= 0) {
                maps[ty][tx]--;
            }
            ty += dy[d];
            tx += + dx[d];
        }
    }
}

void clear_monitor(vector<int> dir, int y, int x) {

    for (int i = 0; i < dir.size(); i++) {
        int d = dir[i];
        int ty = y + dy[d];
        int tx = x + dx[d];

        while(ty < n && tx < m && tx >= 0 && ty >= 0) {
            if(maps[ty][tx] == 6) {
                break;
            } else if(maps[ty][tx] <= 0) {
                maps[ty][tx]++;
            }
            ty += dy[d];
            tx += dx[d];
        }
    }

}

void dfs(int idx) {


    if(idx == cctv.size()) {
        result = min(check(), result);
        return;
    }

    vector<int> dir;
    int y = cctv[idx].first;
    int x = cctv[idx].second;

    if(maps[y][x] == 1) {
        for (int i = 0; i < 4; i++) {
            dir = {i};
            monitor(dir, y, x);
            dfs(idx + 1);
            clear_monitor(dir, y, x);
        }
    } else if(maps[y][x] == 2) {
        for (int i = 0; i < 2; i++) {
            dir = {i, i + 2};
            monitor(dir, y, x);
            dfs(idx + 1);
            clear_monitor(dir, y, x);
        }
    } else if(maps[y][x] == 3) {
        for (int i = 0; i < 4; i++) {
            dir = {i % 4, (i + 1) % 4};
            monitor(dir, y, x);
            dfs(idx + 1);
            clear_monitor(dir, y, x);
        }
    } else if(maps[y][x] == 4) {
        for (int i = 0; i < 4; i++) {
            dir = {i % 4, (i + 1) % 4, (i + 2) % 4};    
            monitor(dir, y, x);
            dfs(idx + 1);
            clear_monitor(dir, y, x);            
        }
    } else {
        dir = {0,1,2,3};
        monitor(dir, y, x);
        dfs(idx + 1);
        clear_monitor(dir, y, x);
    }
}


int main() {
    cin >> n >> m;

    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j <  m; j++) {
            cin >> maps[i][j];
            if (maps[i][j] > 0 && maps[i][j] < 6) {
                cctv.push_back({i, j});
            } 
        }
    }    
    

    dfs(0);

    cout << result;
}