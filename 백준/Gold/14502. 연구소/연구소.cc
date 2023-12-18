#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int lab[8][8];
bool visitedWall[8][8];
bool visited[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int extraWall[3][2];
int cnt = 64;

queue<pair<int, int>> basic_q;


int bfs(queue<pair<int, int>> q) {
    int cnt = q.size();
    while(!q.empty()) {
        int ty = q.front().first;
        int tx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++){
            int y = ty + dy[i];
            int x = tx + dx[i];

            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;
            if(!visited[y][x] && lab[y][x] == 0) {
                visited[y][x] = true;
                q.push(make_pair(y,x));
                cnt++;
            }
        }
    }

    return cnt;
}

void chooseWall() {
    lab[extraWall[0][0]][extraWall[0][1]] = 1;
    lab[extraWall[1][0]][extraWall[1][1]] = 1;
    lab[extraWall[2][0]][extraWall[2][1]] = 1;
}

void rollbackWall() {
    lab[extraWall[0][0]][extraWall[0][1]] = 0;
    lab[extraWall[1][0]][extraWall[1][1]] = 0;
    lab[extraWall[2][0]][extraWall[2][1]] = 0;
}

void dfs(int depth, int idx) {
    if(depth == 3) {
        chooseWall();
        queue<pair<int, int>> test_queue(basic_q);
        memset(visited, false, sizeof(visited));
        int result = bfs(test_queue);
        cnt = min(result, cnt);
        rollbackWall();
        return;
    }

    for(int i = idx; i < n * m; i++) {
        int y = i / m;
        int x = i % m;
        if(!visitedWall[y][x] && lab[y][x] == 0) {
            visitedWall[y][x] = true;
            extraWall[depth][0] = y;
            extraWall[depth][1] = x;
            dfs(depth + 1, i + 1);
            visitedWall[y][x] = false;
        }    
    }
    
}

int main() {
    cin >> n >> m;
    int num;
    int wall_num= 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num;
            if(num == 2){
                basic_q.push(make_pair(i,j));
                visited[i][j] = true;
            }
            else if(num == 1) {
                wall_num++;
            }
            lab[i][j] = num;
        }
    }

    dfs(0,0);
    cout << n * m - (wall_num + 3 + cnt);

    
}


