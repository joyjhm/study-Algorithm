#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;
int bfs(int sy, int sx, int ey, int ex, vector<string>& maps, vector<vector<int>>& visited) {
    queue<pair<int,int>> q;
    visited[sy][sx]++;
    q.push({sy, sx});
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if(y == ey && x == ex) {
            return visited[y][x];
        }

        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if(yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;

            if(maps[yy][xx] == 'X')
                continue;

            if(visited[yy][xx] == -1) {
                visited[yy][xx] = visited[y][x] + 1;
                q.push({yy, xx});
            }
        }
    }
    
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].length();
    int sx, sy, lx, ly, ey, ex;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(maps[i][j] == 'S') {
               sy = i;
               sx = j; 
            }
            else if(maps[i][j] == 'L') {
                ly = i;
                lx = j;
            }
            else if(maps[i][j] == 'E') {
                ey = i;
                ex = j;
            }
        }
    }
    
    vector<vector<int>> visited(n, vector<int>(m, -1));
    int dist = bfs(sy, sx, ly, lx, maps, visited);

    if(dist == -1) {
        return dist;
    }
    for (auto &row : visited) {
        fill(row.begin(), row.end(), -1);
    }

    visited[ly][lx] = dist - 1;
    int answer = bfs(ly, lx, ey, ex, maps, visited);

    return answer;
}