#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n, m;
int visited[500][500];
map<int,int> oil_count;

int bfs(int y, int x, int idx, vector<vector<int>>& land) {
    queue<pair<int,int>> q;
    int cnt = 1;
    
    q.push({y, x});
    visited[y][x] = idx;
    
    while(!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int ty = dy[i] + yy;
            int tx = dx[i] + xx;
            
            if(ty < 0 || ty >= n || tx < 0 || tx >= m)
                continue;
            
            if(land[ty][tx] == 1 && !visited[ty][tx]) {
                visited[ty][tx] = idx;
                cnt++;
                q.push({ty, tx});
            }
        }
    }

    return cnt;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size();
    m = land[0].size();
    int idx = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(land[i][j] == 1 && visited[i][j] == 0) {
                int cnt = bfs(i, j, idx, land);
                oil_count[idx] = cnt;
                idx++;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        vector<bool> v(oil_count.size() + 1, false);
        for (int j = 0; j < n; j++) {
            if(visited[j][i]) {
                v[visited[j][i]] = true;
            }
        }
        
        int cnt = 0;
        for (int k = 1; k < v.size(); k++) {
            if(v[k]) {
                cnt += oil_count[k];
            }
        }
        
        answer = max(answer, cnt);
    }
    
    
    return answer;
}