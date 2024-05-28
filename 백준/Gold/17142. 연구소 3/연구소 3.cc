#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[50][50];
int copy_map[50][50];
int n, m;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};

vector<pair<int,int>> virus;
vector<pair<int,int>> active_virus;
int virus_num;
int result = -1;

void copy() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}

int check() {
    int t = 0;

    for (int i = 0; i < virus_num; i++) {
        int y = virus[i].first;
        int x = virus[i].second;
        copy_map[y][x] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if(copy_map[i][j] == -1) {
                return -1;
            } else {
                t = max(t, copy_map[i][j]);
            }
        }
    }

    return t;
}



void bfs() {

    queue<pair<int,int>> q;
    for (int i = 0; i < active_virus.size(); i++) {
        q.push(active_virus[i]);
        copy_map[active_virus[i].first][active_virus[i].second] = 0;
    }

    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];

            if (yy >= n || xx >= n || yy < 0 || xx < 0)
                continue;
            
            if (copy_map[yy][xx] == -1 || copy_map[yy][xx] == -3) {
                copy_map[yy][xx] = copy_map[y][x] + 1;
                q.push({yy, xx});
            }

        
        } 

    }
}

void dfs(int idx, int depth) {


    if (depth == m) {
        copy();
        bfs();
        int tmp = check();

        if (result == -1 && tmp >= 0) {
            result = tmp;
        }
        else if (result != -1 && tmp >= 0) {
            result = min (result, tmp);
        } 
        return;
    }


    for (int i = idx; i < virus_num; i++) {
        active_virus.push_back(virus[i]);
        dfs(i + 1, depth + 1);
        active_virus.pop_back();
    }
    
}


int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if(tmp == 2) {
                virus.push_back({i, j});
                map[i][j] = -3; // 바이러스
            } 
            else if (tmp == 1) {
                map[i][j] = -2; // 벽
            } else {
                map[i][j] = -1; // 빈 공간
            }

        }
    }
    virus_num = virus.size();
    dfs(0,0);

    cout << result;

}
