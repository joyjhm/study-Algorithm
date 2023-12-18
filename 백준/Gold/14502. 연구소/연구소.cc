#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int n, m;
int lab[8][8];
bool visited[8][8];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int extraWall[3][2];
int result = 64;

queue<pair<int, int>> virus;


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


void dfs(int depth) {
    if(depth == 3) {
        queue<pair<int, int>> test_queue(virus);
        memset(visited, false, sizeof(visited));
        result = min(bfs(test_queue), result);
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {

            if(lab[i][j] == 0) {
                lab[i][j] = 1;
                dfs(depth + 1);
                lab[i][j] = 0;

            }
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
                virus.push(make_pair(i,j));
            }
            else if(num == 1) {
                wall_num++;
            }
            lab[i][j] = num;
        }
    }

    dfs(0);
    cout << n * m - (wall_num + 3 + result);
}


