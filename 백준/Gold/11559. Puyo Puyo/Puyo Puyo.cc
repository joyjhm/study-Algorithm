#include <iostream>
#include <queue>
#include <cstring>
#define MAX_Y 12
#define MAX_X 6
using namespace std;

char arr[12][6];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
bool visited[12][6];

queue<pair<int,int>> q;

bool bfs(int y, int x, char color) {
    
    q.push({y, x});
    visited[y][x] = true;
    vector<pair<int,int>> v;
    v.push_back({y, x});

    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ty = yy + dy[i];
            int tx = xx + dx[i];

            if (ty >= MAX_Y || ty < 0 || tx >= MAX_X || tx < 0)
                continue;
            
            if (arr[ty][tx] == '.')
                continue;
            
            if(arr[ty][tx] == color && !visited[ty][tx]) {
                visited[ty][tx] = true;
                q.push({ty, tx});
                v.push_back({ty, tx});
            }

        }
    }

    if (v.size() >= 4) {
        for (int i = 0; i < v.size(); i++) {
            int yy = v[i].first;
            int xx = v[i].second;
            arr[yy][xx] = '.';
        }

        return true;
    }

    return false;

}

void move() {

    for (int i = 0; i < MAX_X; i++) {
        for (int j = MAX_Y - 2; j >= 0; j--) {
            int idx = j;
            while(arr[idx][i] != '.' && arr[idx + 1][i] == '.') {
                arr[idx + 1][i] = arr[idx][i];
                arr[idx][i] = '.';
                idx++;
            }

        }
    }
}

int main() {


    for (int i = 0; i < MAX_Y; i++) {
        for (int j = 0; j < MAX_X; j++) {
            cin >> arr[i][j];
        }
    }

    bool isBoom = true;
    int answer = 0;
    while (isBoom) {
        isBoom = false;

        memset(visited, false, sizeof(visited));

        for (int i = MAX_Y - 1; i >= 0 ; i--) {
            for (int j = 0; j < MAX_X; j++) {
                if(!visited[i][j] && arr[i][j] != '.') {
                    bool result = bfs(i, j, arr[i][j]);
                    if(result) {
                        isBoom = true;
                    }
                }
            }
        }

        move();
        
        if(isBoom) {
            answer++;
        }
    }

    cout << answer;
    
}